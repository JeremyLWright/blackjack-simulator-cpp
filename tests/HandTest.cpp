#include "HandTest.hpp"
#include "Table.hpp"
#include "BlackjackPlayer.hpp"
#include "Hand.hpp"
#include "Card.hpp"
#include <memory>

using namespace game;

TEST(HandTest, ValueTests)
{
    Table t; BlackjackPlayer jeremy(t); Hand hand(jeremy);
    hand.Add(make_shared<Card>(Card(5, Card::Suite::CLUBS)));
    hand.Add(make_shared<Card>(Card(7, Card::Suite::CLUBS)));
    hand.Add(make_shared<Card>(Card(9, Card::Suite::CLUBS)));
    EXPECT_EQ(21, hand.Value());
}

TEST(HandTest, ValueTest2)
{
    Table t; BlackjackPlayer jeremy(t); Hand hand(jeremy);
    hand.Add(make_shared<Card>(Card(6, Card::Suite::CLUBS)));
    hand.Add(make_shared<AceCard>(AceCard(Card::Suite::CLUBS)));
    EXPECT_EQ(17, hand.Value());
    hand.Add(make_shared<Card>(Card(3, Card::Suite::CLUBS)));
    EXPECT_EQ(20, hand.Value());
}

TEST(HandTest, ValueTest4)
{
    Table t; BlackjackPlayer jeremy(t); Hand hand(jeremy);
    hand.Add(make_shared<Card>(Card(6, Card::Suite::CLUBS)));
    hand.Add(make_shared<AceCard>(AceCard(Card::Suite::CLUBS)));
    EXPECT_EQ(17, hand.Value());
    hand.Add(make_shared<Card>(Card(8, Card::Suite::CLUBS)));
    EXPECT_EQ(15, hand.Value());
}

TEST(HandTest, ValueTest3)
{
    Table t; BlackjackPlayer jeremy(t); Hand hand(jeremy);
    hand.Add(make_shared<AceCard>(AceCard(Card::Suite::CLUBS)));
    hand.Add(make_shared<Card>(Card(6, Card::Suite::CLUBS)));
    EXPECT_EQ(17, hand.Value());
    hand.Add(make_shared<Card>(Card(8, Card::Suite::CLUBS)));
    EXPECT_EQ(15, hand.Value());
}

TEST(HandTest, ValueTest5)
{
    Table t; BlackjackPlayer jeremy(t); Hand hand(jeremy);
    hand.Add(make_shared<AceCard>(AceCard(Card::Suite::CLUBS)));
    hand.Add(make_shared<AceCard>(AceCard(Card::Suite::CLUBS)));
    EXPECT_EQ(12, hand.Value());
    hand.Add(make_shared<Card>(Card(8, Card::Suite::CLUBS)));
    EXPECT_EQ(20, hand.Value());
    hand.Add(make_shared<Card>(Card(2, Card::Suite::CLUBS)));
    EXPECT_EQ(12, hand.Value());
}

TEST(HandTest, Bets)
{
    Table t; BlackjackPlayer jeremy(t); Hand hand(jeremy);
#if __clang__
    shared_ptr<Bet> b(new Bet(100, Outcome("Blackjack", make_pair(3,2))));
#else
    shared_ptr<Bet> b{new Bet(100, Outcome("Blackjack", make_pair(3,2)))};
#endif
    hand.SetBet(b);
    EXPECT_EQ(150, hand.GetBet()->WinAmount());
}


