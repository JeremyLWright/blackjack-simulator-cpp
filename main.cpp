#ifndef _MAIN
#define _MAIN

#include "Application/BlackjackGame.hpp"
#include "Application/BlackjackPlayer.hpp"
#include "Application/Table.hpp"
#include <iostream>

using namespace std;

int main(int argc, const char *argv[])
{
    Casino::Table* mainTable = new Casino::Table();
    Casino::BlackjackPlayer* Jeremy = new Casino::BlackjackPlayer(*mainTable);
    mainTable->AddPlayer(Jeremy);
    auto shoe = new Casino::Shoe(4, 3);
    Casino::BlackjackGame game(*shoe, *mainTable);
    for(int i = 0; i < 10; ++i)
    {
        game.Cycle();
        cout << "Play again" << endl;
    }
    return 0;
}

#endif /* end of include guard: _MAIN */
