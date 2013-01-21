#include <vector>
#include <algorithm>
#include "Card.hpp"
#include <gtest/gtest.h>
using namespace std;
TEST(Cards, CardSort)
{
    vector<game::Card> cards;
    cards.push_back(game::Card(9, game::Card::Suite::CLUBS));
    cards.push_back(game::Card(2, game::Card::Suite::CLUBS));
    cards.push_back(game::AceCard(game::Card::Suite::CLUBS));
    std::sort(std::begin(cards), std::end(cards));
    EXPECT_EQ(2, cards[0].HardValue());
    EXPECT_EQ(9, cards[1].HardValue());
    EXPECT_EQ(11, cards[2].HardValue());
}
