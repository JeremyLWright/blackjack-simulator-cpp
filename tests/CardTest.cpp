#include <vector>
#include <algorithm>
#include "Card.hpp"
#include <gtest/gtest.h>
using namespace std;
TEST(Cards, CardSort)
{
    vector<Casino::Card> cards;
    cards.push_back(Casino::Card(9, Casino::Card::Suite::CLUBS));
    cards.push_back(Casino::Card(2, Casino::Card::Suite::CLUBS));
    cards.push_back(Casino::AceCard(Casino::Card::Suite::CLUBS));
    std::sort(std::begin(cards), std::end(cards));
    EXPECT_EQ(2, cards[0].HardValue());
    EXPECT_EQ(9, cards[1].HardValue());
    EXPECT_EQ(11, cards[2].HardValue());
}
