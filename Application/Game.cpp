#include "Game.hpp"
namespace Application {
    Game::Game ()
    {
    }

    Game::~Game ()
    {
    }

    Game::Run()
    {
        //Shuffle the cards
        

        //Address each player at the table
        

        //Offer Insurance to the player


        shoe_.Shuffle();
        for(auto player : players_)
        {
            InitPlayer(player);
        }

        InitPlayer(dealer_);
        auto dealersHand = dealer_.GetFirstHand();
        if(dealersHand->GetUpCard()->OfferInsurance())
            Insurance();
        
        //Initial deal, and splitting...
        for(auto player : players_)
        {
            for(auto playersHand : player)
            {
                if(playersHand->Splittable() && !playersHand->SplitDeclined())
                {
                    auto splitHand = player.Split(*playersHand.get());
                    splitHand->Add(*dealItr_);
                    dealItr_++;      
                    playersHand->Add(*dealItr_);
                    dealItr_++;      
                }
            }
        }

        //Fill hands, and betting...
        for(auto player : players_)
        {
            for(auto playersHand : player)
            {
                FillHand(*playersHand.get());
            }
        }

        FillHand(*dealersHand.get());

        if(dealersHand->Busted())
        {
            //Resolve all bets as winners
            for(auto player : players_)
            {
                for(auto playersHand : player)
                {
                    player.Win(*playersHand->GetBet().get());
                }
            }
        }

        for(auto player: players_)
        {
            for(auto playersHand : player)
            {
                if(playersHand->Value() > dealersHand->Value())
                {
                    player.Win(*playersHand->GetBet().get());
                }
            }
        }
    }
} /* Application */
