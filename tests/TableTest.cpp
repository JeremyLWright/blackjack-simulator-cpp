#include <gtest/gtest.h>
#include "Table.hpp"
#include "BlackjackPlayer.hpp"
using namespace game;

TEST(Tables, PlaceBet)
{
    Table t;
    BlackjackPlayer jeremy(t);
    Hand first(jeremy);
    auto bet = Bet(1000, Outcome("Jeremy'sBet", make_pair(3,2)));
    EXPECT_THROW( t.PlaceBet(move(bet), first), TableLimitException);
}


TEST(Tables, PlaceBetClean)
{
    Table t(10000);
    BlackjackPlayer jeremy(t);
    Hand first(jeremy);
    auto bet = Bet(1000, Outcome("Jeremy'sBet", make_pair(3,2)));
    EXPECT_NO_THROW( t.PlaceBet(move(bet), first));
}
