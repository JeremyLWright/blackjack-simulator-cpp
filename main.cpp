#ifndef _MAIN
#define _MAIN

#include "Application/BlackjackGame.hpp"
#include "Application/BlackjackPlayer.hpp"
#include "Application/Table.hpp"
#include <iostream>

using namespace std;

int main(int argc, const char *argv[])
{
    Casino::Table::Ptr mainTable = new Casino::Table();
    Casino::BlackjackPlayer* Jeremy = new Casino::BlackjackPlayer();
	Jeremy->AddMoney(1000);
    auto shoe = new Casino::Shoe(4);
    Casino::BlackjackGame game(*shoe, mainTable);

    game.Cycle();
    cout << "Play again" << endl;
	string c = "";
	cin >> c;
    
    return 0;
}

#endif /* end of include guard: _MAIN */
