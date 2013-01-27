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

TEST(Cards, AceCard)
{
	Card::Ptr ace = new AceCard(Card::Suite::HEARTS);
	cout << ace->ToString() << endl;
}

TEST(Cards, FaceCard)
{
	auto face_rank = new Card::FaceRank(Card::FaceRank::KING);

	Card::Ptr face = new FaceCard(*face_rank,Card::Suite::HEARTS);
	cout << face->ToString() << endl;
}
