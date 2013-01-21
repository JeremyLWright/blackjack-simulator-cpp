#include <gtest/gtest.h>
#include "Bet.hpp"

TEST(Bets, WinLose)
{
    game::Bet b(100, game::Outcome("Blackjack", make_pair(3,2)));
    EXPECT_EQ(150, b.WinAmount());
    EXPECT_EQ(100, b.LoseAmount());
}
