int spi_bitbang_start(struct spi_bitbang *bitbang)
{
        int     status;

        if (!bitbang->master || !bitbang->chipselect)
                return -EINVAL;

        INIT_WORK(&bitbang->work, bitbang_work);
        spin_lock_init(&bitbang->lock);
        INIT_LIST_HEAD(&bitbang->queue);

        if (!bitbang->master->mode_bits)
                bitbang->master->mode_bits = SPI_CPOL | SPI_CPHA | bitbang->flags;

        if (!bitbang->master->transfer)
                bitbang->master->transfer = spi_bitbang_transfer;
        if (!bitbang->txrx_bufs) {
                bitbang->use_dma = 0;
                bitbang->txrx_bufs = spi_bitbang_bufs;
                if (!bitbang->master->setup) {
                        if (!bitbang->setup_transfer)
                                bitbang->setup_transfer =
                                         spi_bitbang_setup_transfer;
                        bitbang->master->setup = spi_bitbang_setup;
                        bitbang->master->cleanup = spi_bitbang_cleanup;
                }
        } else if (!bitbang->master->setup)
                return -EINVAL;
        if (bitbang->master->transfer == spi_bitbang_transfer &&
                        !bitbang->setup_transfer)
                return -EINVAL;

        /* this task is the only thing to touch the SPI bits */
        bitbang->busy = 0;
        bitbang->workqueue = create_singlethread_workqueue(
                        dev_name(bitbang->master->dev.parent));
        if (bitbang->workqueue == NULL) {
                status = -EBUSY;
                goto err1;
        }

        /* driver may get busy before register() returns, especially
         * if someone registered boardinfo for devices
         */
        status = spi_register_master(bitbang->master);
        if (status < 0)
                goto err2;

        return status;

err2:
        destroy_workqueue(bitbang->workqueue);
err1:
        return status;
}

