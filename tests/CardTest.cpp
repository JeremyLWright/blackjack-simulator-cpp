#include <vector>
#include <algorithm>
#include "Card.hpp"
#include <gtest/gtest.h>
using namespace std;
using namespace Casino;
TEST(Cards, CardSort)
{
    vector<Casino::Card*> cards;
    auto rank_9 = new Card::ValueRank(9);
    auto rank_2 = new Card::ValueRank(2);
    
    cards.push_back(new Casino::Card(*rank_9, Casino::Card::Suite::CLUBS));
    cards.push_back(new Casino::Card(*rank_2, Casino::Card::Suite::CLUBS));
    cards.push_back(new Casino::AceCard(Casino::Card::Suite::CLUBS));
    
    std::sort(std::begin(cards), std::end(cards), [](Card* lhs, Card* rhs){ return (lhs->HardValue() < rhs->HardValue()); });
    
    EXPECT_EQ(2, cards[0]->HardValue());
    EXPECT_EQ(9, cards[1]->HardValue());
    EXPECT_EQ(11, cards[2]->HardValue());
    
    delete rank_9;
    delete rank_2;
}
