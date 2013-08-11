#include "HandTest.hpp"
#include "Table.hpp"
#include "BlackjackPlayer.hpp"
#include "Hand.hpp"
#include "Card.hpp"
#include <memory>

using namespace Casino;

TEST(HandTest, ValueTests)
{
    Table t; BlackjackPlayer jeremy; Hand hand(jeremy);

    hand.Add(new Card(5, Card::Suite::CLUBS));
    hand.Add(new Card(7, Card::Suite::CLUBS));
    hand.Add(new Card(9, Card::Suite::CLUBS));
    
    EXPECT_EQ(21, hand.Value());
}

TEST(HandTest, ValueTest2)
{
    Table t; BlackjackPlayer jeremy; Hand hand(jeremy);

    hand.Add(new Card(6, Card::Suite::CLUBS));
    hand.Add(new AceCard(Card::Suite::CLUBS));
    
    EXPECT_EQ(17, hand.Value());
    hand.Add(new Card(3, Card::Suite::CLUBS));
    EXPECT_EQ(20, hand.Value());
}

TEST(HandTest, ValueTest4)
{
    Table t; BlackjackPlayer jeremy; Hand hand(jeremy);
    hand.Add(new Card(6, Card::Suite::CLUBS));
    hand.Add(new AceCard(Card::Suite::CLUBS));
   
    EXPECT_EQ(17, hand.Value());
    hand.Add(new Card(8, Card::Suite::CLUBS));
    EXPECT_EQ(15, hand.Value());
}

TEST(HandTest, ValueTest5)
{
    Table t; BlackjackPlayer jeremy; Hand hand(jeremy);

    hand.Add(new AceCard(Card::Suite::CLUBS));
    hand.Add(new AceCard(Card::Suite::CLUBS));
    EXPECT_EQ(12, hand.Value());

    hand.Add(new Card(8, Card::Suite::CLUBS));
    EXPECT_EQ(20, hand.Value());

    hand.Add(new Card(2, Card::Suite::CLUBS));
    EXPECT_EQ(12, hand.Value());
}

TEST(HandTest, Bets)
{
    Table t; BlackjackPlayer jeremy; Hand hand(jeremy);
    auto b  = new Bet(100, Odds("Blackjack", make_pair(3,2)));
    hand.SetBet(*b);
    EXPECT_EQ(150, hand.GetBet().WinAmount());
}


