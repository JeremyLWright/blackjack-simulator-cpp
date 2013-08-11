#include "gtest/gtest.h"
#include "BettingStragety.hpp"
#include "Hand.hpp"
#include "Card.hpp"
#include "BlackjackPlayer.hpp"
using namespace Casino;

class StragetyTest : public ::testing::Test {
    protected:
        virtual void SetUp()
        {
            perfectStrat = new PerfectBlackjack();
        }

        virtual void TearDown()
        {
            delete petfectStrat;
        }
        Hand::Ptr hand;
        BettingStragety* perfectStrat;
};

TEST_F(StragetyTest, Stands)
{
    auto fst = new Casino::Card(2, Casino::Card::Suite::CLUBS);
    auto snd = new Casino::Card(2, Casino::Card::Suite::CLUBS);

    hand.Add(fst);
    hand.Add(snd);
    
    auto dealerfst = new Casino::Card(2, Casino::Card::Suite::CLUBS);

    EXPECT_EQ(true, perfectStrat->Hit(hand, dealerfst));
}
