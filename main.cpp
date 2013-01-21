#ifndef _MAIN
#define _MAIN

#include "Application/BlackjackGame.hpp"
#include "Application/BlackjackPlayer.hpp"
#include "Application/Table.hpp"

int main(int argc, const char *argv[])
{
    game::Table* mainTable = new game::Table();
    game::BlackjackPlayer* Jeremy = new game::BlackjackPlayer();
    mainTable->AddPlayer(Jeremy);
    game::BlackjackGame game(game::Shoe(4, 3), mainTable);
    for(int i = 0; i < 10; ++i)
    {
        game.Play();
    }
    return 0;
}

#endif /* end of include guard: _MAIN */
