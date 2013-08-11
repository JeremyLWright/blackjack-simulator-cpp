#include <vector>
#include <algorithm>
#include "Card.hpp"
#include <gtest/gtest.h>
using namespace std;
using namespace Casino;
TEST(Cards, CardSort)
{
    vector<Casino::Card*> cards;
    
    cards.push_back(new Casino::Card(9, Casino::Card::Suite::CLUBS));
    cards.push_back(new Casino::Card(2, Casino::Card::Suite::CLUBS));
    cards.push_back(new Casino::AceCard(Casino::Card::Suite::CLUBS));
    
    std::sort(std::begin(cards), std::end(cards), [](Card* lhs, Card* rhs){ return (lhs->HardValue() < rhs->HardValue()); });
    
    EXPECT_EQ(2, cards[0]->HardValue());
    EXPECT_EQ(9, cards[1]->HardValue());
    EXPECT_EQ(11, cards[2]->HardValue());
}

TEST(Cards, AceCard)
{
	Card::Ptr ace = new AceCard(Card::Suite::HEARTS);
	cout << ace->ToString() << endl;
}

TEST(Cards, FaceCard)
{
	Card::Ptr face = new FaceCard(FaceRank::KING,Card::Suite::HEARTS);
	cout << face->ToString() << endl;
}
