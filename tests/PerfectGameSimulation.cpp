#include "gtest/gtest.h"
#include "PlayerView.hpp"
#include "BlackjackGame.hpp"
#include "BlackjackPlayer.hpp"
#include "Card.hpp"
#include "Table.hpp"
#include "Shoe.hpp"

using namespace Casino;

TEST(Simulation, PerfectGame)
{
    Casino::Table::Ptr mainTable = new Casino::Table();
    PerfectView* view = new PerfectView();
    BlackjackPlayer* Jeremy = new BlackjackPlayer(view);
    Jeremy->AddMoney(1000);
    Shoe shoe(4);

    Casino::BlackjackGame game(shoe, mainTable);
    game.AddPlayer(Jeremy);
    for(int i = 0; i < 100000; ++i)
        try
        {
            game.Cycle();
        }
        catch(Casino::EndOfShoeException const &)
        {
            shoe.Shuffle();
        }
        catch(OutOfMoneyException const & e)
        {
            cout << "Player: "<< Jeremy << " is out of Money:" << e.player_ << endl;
            break;
        }

    cout << "Simulated Win Ratio: " << view->GetWinRatio() << "%." << endl;
}
