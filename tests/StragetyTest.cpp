#include "gtest/gtest.h"
#include <tuple>
#include "BettingStragety.hpp"
#include "Hand.hpp"
#include "Card.hpp"
#include "BlackjackPlayer.hpp"
#include <random>
#include <numeric>
#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>


template <typename T>
vector<pair<T, T>> zip(vector<T> a, vector<T> b)
{
    auto j = begin(b);
    vector<pair<T, T>> zips;
    for(auto i = begin(a); i < end(a); ++i)
    {
        zips.push_back(make_pair(*i, *j));
        ++j;
    }
    return zips;
}


using namespace Casino;

class StragetyTest : public ::testing::Test {
    protected:
        virtual void SetUp()
        {
            perfectStrat = new PerfectBlackjack();
        }

        virtual void TearDown()
        {
            delete perfectStrat;
        }

        virtual Hand::Ptr generateHand(int value)
        {
            Hand::Ptr h = new Hand();
            for(auto i : constrained_sum_sample(5, value))
            {
                h->Add(new Casino::Card(i, Card::Suite::CLUBS));
            }
            return h;
        }

        vector<int> constrained_sum_sample(int n, int total)
        {
            vector<int> result;
            std::random_device rd;
            std::default_random_engine generator(rd());
            std::uniform_int_distribution<int> distribution(2,10);
            auto cards = std::bind(distribution, generator);

            vector<int> dividers;
            for(int i = 1; i < n; ++i) 
                dividers.push_back(cards());
            sort(begin(dividers), end(dividers));

            auto top = dividers;
            auto bot = dividers;
            top.push_back(total);
            bot.push_back(0);
            sort(begin(bot), end(bot));
            for(auto ab : zip(top, bot))
            {   
                result.push_back(ab.first - ab.second);
            }
            return result;
        }

      

        BettingStragety* perfectStrat;
};
#if 0
TEST_F(StragetyTest, Stands17_20)
{
    auto fst = new Casino::Card(10, Casino::Card::Suite::CLUBS);
    auto snd = new Casino::Card(7, Casino::Card::Suite::CLUBS);

    hand->Add(snd);
    EXPECT_EQ(17, hand->Value());

    for(int i = 2; i <= 10; ++i)
    {
        auto dealerfst = new Casino::Card(i, Casino::Card::Suite::CLUBS);
        EXPECT_EQ(i, dealerfst->Rank());
        EXPECT_EQ(false, perfectStrat->Hit(*hand, dealerfst));
        delete dealerfst;
    }
    delete fst;
    delete snd;
}
#endif


TEST_F(StragetyTest, Stands16)
{
    enum ExpectedAction {
        STAND,
        HIT,
        DOUBLE,
        SPLIT
    };

    typedef struct {
        int playersValue;
        int dealersValue;
        ExpectedAction action;
    } PerfectStragetyAction;

    vector<PerfectStragetyAction> perfectActions 
    {
        {20, 2, STAND}, {20, 3, STAND}, {20, 4, STAND}, {20, 5, STAND}, {20, 6, STAND}, {20, 7, STAND}, {20, 8, STAND}, {20, 9, STAND}, {20, 10, STAND},
        {19, 2, STAND}, {19, 3, STAND}, {19, 4, STAND}, {19, 5, STAND}, {19, 6, STAND}, {19, 7, STAND}, {19, 8, STAND}, {19, 9, STAND}, {19, 10, STAND},
        {18, 2, STAND}, {18, 3, STAND}, {18, 4, STAND}, {18, 5, STAND}, {18, 6, STAND}, {18, 7, STAND}, {18, 8, STAND}, {18, 9, STAND}, {18, 10, STAND},
        {17, 2, STAND}, {17, 3, STAND}, {17, 4, STAND}, {17, 5, STAND}, {17, 6, STAND}, {17, 7, STAND}, {17, 8, STAND}, {17, 9, STAND}, {17, 10, STAND},
        {16, 2, STAND}, {16, 3, STAND}, {16, 4, STAND}, {16, 5, STAND}, {16, 6, STAND}, {16, 7, HIT},   {16, 8, HIT},   {16, 9, HIT},   {16, 10, HIT},
        {15, 2, STAND}, {15, 3, STAND}, {15, 4, STAND}, {15, 5, STAND}, {15, 6, STAND}, {15, 7, HIT},   {15, 8, HIT},   {15, 9, HIT},   {15, 10, HIT},
        {14, 2, STAND}, {14, 3, STAND}, {14, 4, STAND}, {14, 5, STAND}, {14, 6, STAND}, {14, 7, HIT},   {14, 8, HIT},   {14, 9, HIT},   {14, 10, HIT},
        {13, 2, STAND}, {13, 3, STAND}, {13, 4, STAND}, {13, 5, STAND}, {13, 6, STAND}, {13, 7, HIT},   {13, 8, HIT},   {13, 9, HIT},   {13, 10, HIT},
        {12, 2, HIT},   {12, 3, HIT},   {12, 4, STAND}, {12, 5, STAND}, {12, 6, STAND}, {12, 7, HIT},   {12, 8, HIT},   {12, 9, HIT},   {12, 10, HIT},
        {11, 2, DOUBLE},{11, 3, DOUBLE},{11, 4, DOUBLE},{11, 5, DOUBLE},{11, 6, DOUBLE},{11, 7, DOUBLE},{11, 8, DOUBLE},{11, 9, DOUBLE},{11, 10, DOUBLE},
        {10, 2, DOUBLE},{10, 3, DOUBLE},{10, 4, DOUBLE},{10, 5, DOUBLE},{10, 6, DOUBLE},{10, 7, DOUBLE},{10, 8, DOUBLE},{10, 9, DOUBLE},{10, 10, HIT},
        {9, 2, HIT},    {9, 3, DOUBLE}, {9, 4, DOUBLE}, {9, 5, DOUBLE}, {9, 6, DOUBLE}, {9, 7, HIT},    {9, 8, HIT},    {9, 9, HIT},    {9, 10, HIT},
        {8, 2, HIT},   {8, 3, HIT},   {8, 4, HIT}, {8, 5, HIT}, {8, 6, HIT}, {8, 7, HIT},   {8, 8, HIT},   {8, 9, HIT},   {8, 10, HIT},
        {7, 2, HIT},   {7, 3, HIT},   {7, 4, HIT}, {7, 5, HIT}, {7, 6, HIT}, {7, 7, HIT},   {7, 8, HIT},   {7, 9, HIT},   {7, 10, HIT},
        {6, 2, HIT},   {6, 3, HIT},   {6, 4, HIT}, {6, 5, HIT}, {6, 6, HIT}, {6, 7, HIT},   {6, 8, HIT},   {6, 9, HIT},   {6, 10, HIT},
        {5, 2, HIT},   {5, 3, HIT},   {5, 4, HIT}, {5, 5, HIT}, {5, 6, HIT}, {5, 7, HIT},   {5, 8, HIT},   {5, 9, HIT},   {5, 10, HIT},
    };

    auto ExpectHit = [&](const char* m_expr,
            const char* n_expr,
            Hand* hand,
            Card::Ptr dealer) -> ::testing::AssertionResult
    {
        if(perfectStrat->Hit(*hand, dealer))
            return ::testing::AssertionSuccess();
        
        return ::testing::AssertionFailure()
            << "Stragety does not Hit with Hand: " << hand->Value() << " and dealer upcard: " << dealer->Rank();
    };
    auto ExpectStand = [&](const char* m_expr,
            const char* n_expr,
            Hand* hand,
            Card::Ptr dealer) -> ::testing::AssertionResult
    {
        if(!perfectStrat->Hit(*hand, dealer))
            return ::testing::AssertionSuccess();
        
        return ::testing::AssertionFailure()
            << "Stragety does not Stand with Hand: " << hand->Value() << " and dealer upcard: " << dealer->Rank();
    };
    auto ExpectDouble = [&](const char* m_expr,
            const char* n_expr,
            Hand* hand,
            Card::Ptr dealer) -> ::testing::AssertionResult
    {
        if(perfectStrat->DoubleDown(*hand, dealer))
            return ::testing::AssertionSuccess();
        
        return ::testing::AssertionFailure()
            << "Stragety does not Stand with Hand: " << hand->Value() << " and dealer upcard: " << dealer->Rank();
    };
    for(auto action : perfectActions)
    {
        auto hand = generateHand(action.playersValue);
        ASSERT_EQ(action.playersValue, hand->Value());
        auto dealerCard = new Casino::Card(action.dealersValue, Card::Suite::CLUBS);
        switch(action.action)
        {
            case STAND:
                ASSERT_PRED_FORMAT2(ExpectStand, hand, dealerCard);
                break;
            case HIT:
                ASSERT_PRED_FORMAT2(ExpectHit, hand, dealerCard);
                break;
            case DOUBLE:
                ASSERT_PRED_FORMAT2(ExpectDouble, hand, dealerCard);
                break;
            case SPLIT:
                break;
        }
    }
#if 0
    /* Make a 17 hand */
    auto fst = new Casino::Card(10, Casino::Card::Suite::CLUBS);
    auto snd = new Casino::Card(7, Casino::Card::Suite::CLUBS);

    hand->Add(fst);
    hand->Add(snd);
    EXPECT_EQ(17, hand->Value());
    for(int i = 2; i <= 10; ++i)
    {
        auto dealerfst = new Casino::Card(i, Casino::Card::Suite::CLUBS);
        perfectActions.push_back(make_tuple(hand, dealerfst, ExpectedAction::STAND));
        delete dealerfst;
    }
    

    auto fst = new Casino::Card(10, Casino::Card::Suite::CLUBS);
    auto snd = new Casino::Card(6, Casino::Card::Suite::CLUBS);

    hand->Add(fst);
    hand->Add(snd);
    EXPECT_EQ(16, hand->Value());

    for(int i = 2; i <= 6; ++i)
    {
        auto dealerfst = new Casino::Card(i, Casino::Card::Suite::CLUBS);
        EXPECT_EQ(i, dealerfst->Rank());
        EXPECT_EQ(false, perfectStrat->Hit(*hand, dealerfst));
        delete dealerfst;
    }
    for(int i = 7; i <= 10; ++i)
    {
        auto dealerfst = new Casino::Card(i, Casino::Card::Suite::CLUBS);
        EXPECT_EQ(i, dealerfst->Rank());
        EXPECT_EQ(true, perfectStrat->Hit(*hand, dealerfst));
        delete dealerfst;
    }
    
    delete fst;
    delete snd;
#endif
}
