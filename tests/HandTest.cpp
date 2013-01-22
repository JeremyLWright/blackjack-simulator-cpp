#include "HandTest.hpp"
#include "Table.hpp"
#include "BlackjackPlayer.hpp"
#include "Hand.hpp"
#include "Card.hpp"
#include <memory>

using namespace Casino;

TEST(HandTest, ValueTests)
{
    Table t; BlackjackPlayer jeremy(t); Hand hand(jeremy);
    auto rank_9 = new Card::ValueRank(9);
    auto rank_7 = new Card::ValueRank(7);
    auto rank_5 = new Card::ValueRank(5);

    hand.Add(make_shared<Card>(Card(*rank_5, Card::Suite::CLUBS)));
    hand.Add(make_shared<Card>(Card(*rank_7, Card::Suite::CLUBS)));
    hand.Add(make_shared<Card>(Card(*rank_9, Card::Suite::CLUBS)));
    
    EXPECT_EQ(21, hand.Value());
}

TEST(HandTest, ValueTest2)
{
    Table t; BlackjackPlayer jeremy(t); Hand hand(jeremy);

    auto rank_6 = new Card::ValueRank(6);
    hand.Add(make_shared<Card>(Card(*rank_6, Card::Suite::CLUBS)));
    hand.Add(make_shared<AceCard>(AceCard(Card::Suite::CLUBS)));
    
    EXPECT_EQ(17, hand.Value());
    auto rank_3 = new Card::ValueRank(3);
    hand.Add(make_shared<Card>(Card(*rank_3, Card::Suite::CLUBS)));
    EXPECT_EQ(20, hand.Value());
}

TEST(HandTest, ValueTest4)
{
    Table t; BlackjackPlayer jeremy(t); Hand hand(jeremy);
    auto rank_6 = new Card::ValueRank(6);
    hand.Add(make_shared<Card>(Card(*rank_6, Card::Suite::CLUBS)));
    hand.Add(make_shared<AceCard>(AceCard(Card::Suite::CLUBS)));
    
    EXPECT_EQ(17, hand.Value());
    auto rank_8 = new Card::ValueRank(8);
    hand.Add(make_shared<Card>(Card(*rank_8, Card::Suite::CLUBS)));
    EXPECT_EQ(15, hand.Value());
}

TEST(HandTest, ValueTest5)
{
    Table t; BlackjackPlayer jeremy(t); Hand hand(jeremy);

    hand.Add(make_shared<AceCard>(AceCard(Card::Suite::CLUBS)));
    hand.Add(make_shared<AceCard>(AceCard(Card::Suite::CLUBS)));
    EXPECT_EQ(12, hand.Value());

    auto rank_8 = new Card::ValueRank(8);
    hand.Add(make_shared<Card>(Card(*rank_8, Card::Suite::CLUBS)));
    EXPECT_EQ(20, hand.Value());

    auto rank_2 = new Card::ValueRank(2);
    hand.Add(make_shared<Card>(Card(*rank_2, Card::Suite::CLUBS)));
    EXPECT_EQ(12, hand.Value());
}

TEST(HandTest, Bets)
{
    Table t; BlackjackPlayer jeremy(t); Hand hand(jeremy);
    auto b  = new Bet(100, Odds("Blackjack", make_pair(3,2)));
    hand.SetBet(*b);
    EXPECT_EQ(150, hand.GetBet().WinAmount());
}


