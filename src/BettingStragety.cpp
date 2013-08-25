#include "BettingStragety.hpp"

#include <algorithm>
using namespace Casino;
namespace {

typedef struct {
        int playersValue;
        int dealersValue;
        PerfectBlackjack::ExpectedAction action;
    } PerfectStragetyAction;

vector<PerfectStragetyAction> perfectActions 
{
    {20, 2, PerfectBlackjack::STAND}, {20, 3, PerfectBlackjack::STAND}, {20, 4, PerfectBlackjack::STAND}, {20, 5, PerfectBlackjack::STAND}, {20, 6, PerfectBlackjack::STAND}, {20, 7, PerfectBlackjack::STAND}, {20, 8, PerfectBlackjack::STAND}, {20, 9, PerfectBlackjack::STAND}, {20, 10, PerfectBlackjack::STAND},
    {19, 2, PerfectBlackjack::STAND}, {19, 3, PerfectBlackjack::STAND}, {19, 4, PerfectBlackjack::STAND}, {19, 5, PerfectBlackjack::STAND}, {19, 6, PerfectBlackjack::STAND}, {19, 7, PerfectBlackjack::STAND}, {19, 8, PerfectBlackjack::STAND}, {19, 9, PerfectBlackjack::STAND}, {19, 10, PerfectBlackjack::STAND},
    {18, 2, PerfectBlackjack::STAND}, {18, 3, PerfectBlackjack::STAND}, {18, 4, PerfectBlackjack::STAND}, {18, 5, PerfectBlackjack::STAND}, {18, 6, PerfectBlackjack::STAND}, {18, 7, PerfectBlackjack::STAND}, {18, 8, PerfectBlackjack::STAND}, {18, 9, PerfectBlackjack::STAND}, {18, 10, PerfectBlackjack::STAND},
    {17, 2, PerfectBlackjack::STAND}, {17, 3, PerfectBlackjack::STAND}, {17, 4, PerfectBlackjack::STAND}, {17, 5, PerfectBlackjack::STAND}, {17, 6, PerfectBlackjack::STAND}, {17, 7, PerfectBlackjack::STAND}, {17, 8, PerfectBlackjack::STAND}, {17, 9, PerfectBlackjack::STAND}, {17, 10, PerfectBlackjack::STAND},
    {16, 2, PerfectBlackjack::STAND}, {16, 3, PerfectBlackjack::STAND}, {16, 4, PerfectBlackjack::STAND}, {16, 5, PerfectBlackjack::STAND}, {16, 6, PerfectBlackjack::STAND}, {16, 7, PerfectBlackjack::HIT},   {16, 8, PerfectBlackjack::HIT},   {16, 9, PerfectBlackjack::HIT},   {16, 10, PerfectBlackjack::HIT},
    {15, 2, PerfectBlackjack::STAND}, {15, 3, PerfectBlackjack::STAND}, {15, 4, PerfectBlackjack::STAND}, {15, 5, PerfectBlackjack::STAND}, {15, 6, PerfectBlackjack::STAND}, {15, 7, PerfectBlackjack::HIT},   {15, 8, PerfectBlackjack::HIT},   {15, 9, PerfectBlackjack::HIT},   {15, 10, PerfectBlackjack::HIT},
    {14, 2, PerfectBlackjack::STAND}, {14, 3, PerfectBlackjack::STAND}, {14, 4, PerfectBlackjack::STAND}, {14, 5, PerfectBlackjack::STAND}, {14, 6, PerfectBlackjack::STAND}, {14, 7, PerfectBlackjack::HIT},   {14, 8, PerfectBlackjack::HIT},   {14, 9, PerfectBlackjack::HIT},   {14, 10, PerfectBlackjack::HIT},
    {13, 2, PerfectBlackjack::STAND}, {13, 3, PerfectBlackjack::STAND}, {13, 4, PerfectBlackjack::STAND}, {13, 5, PerfectBlackjack::STAND}, {13, 6, PerfectBlackjack::STAND}, {13, 7, PerfectBlackjack::HIT},   {13, 8, PerfectBlackjack::HIT},   {13, 9, PerfectBlackjack::HIT},   {13, 10, PerfectBlackjack::HIT},
    {12, 2, PerfectBlackjack::HIT},   {12, 3, PerfectBlackjack::HIT},   {12, 4, PerfectBlackjack::STAND}, {12, 5, PerfectBlackjack::STAND}, {12, 6, PerfectBlackjack::STAND}, {12, 7, PerfectBlackjack::HIT},   {12, 8, PerfectBlackjack::HIT},   {12, 9, PerfectBlackjack::HIT},   {12, 10, PerfectBlackjack::HIT},
    {11, 2, PerfectBlackjack::DOUBLE},{11, 3, PerfectBlackjack::DOUBLE},{11, 4, PerfectBlackjack::DOUBLE},{11, 5, PerfectBlackjack::DOUBLE},{11, 6, PerfectBlackjack::DOUBLE},{11, 7, PerfectBlackjack::DOUBLE},{11, 8, PerfectBlackjack::DOUBLE},{11, 9, PerfectBlackjack::DOUBLE},{11, 10, PerfectBlackjack::DOUBLE},
    {10, 2, PerfectBlackjack::DOUBLE},{10, 3, PerfectBlackjack::DOUBLE},{10, 4, PerfectBlackjack::DOUBLE},{10, 5, PerfectBlackjack::DOUBLE},{10, 6, PerfectBlackjack::DOUBLE},{10, 7, PerfectBlackjack::DOUBLE},{10, 8, PerfectBlackjack::DOUBLE},{10, 9, PerfectBlackjack::DOUBLE},{10, 10, PerfectBlackjack::HIT},
    {9, 2, PerfectBlackjack::HIT},    {9, 3, PerfectBlackjack::DOUBLE}, {9, 4, PerfectBlackjack::DOUBLE}, {9, 5, PerfectBlackjack::DOUBLE}, {9, 6, PerfectBlackjack::DOUBLE}, {9, 7, PerfectBlackjack::HIT},    {9, 8, PerfectBlackjack::HIT},    {9, 9, PerfectBlackjack::HIT},    {9, 10, PerfectBlackjack::HIT},
    {8, 2, PerfectBlackjack::HIT},   {8, 3, PerfectBlackjack::HIT},   {8, 4, PerfectBlackjack::HIT}, {8, 5, PerfectBlackjack::HIT}, {8, 6, PerfectBlackjack::HIT}, {8, 7, PerfectBlackjack::HIT},   {8, 8, PerfectBlackjack::HIT},   {8, 9, PerfectBlackjack::HIT},   {8, 10, PerfectBlackjack::HIT},
    {7, 2, PerfectBlackjack::HIT},   {7, 3, PerfectBlackjack::HIT},   {7, 4, PerfectBlackjack::HIT}, {7, 5, PerfectBlackjack::HIT}, {7, 6, PerfectBlackjack::HIT}, {7, 7, PerfectBlackjack::HIT},   {7, 8, PerfectBlackjack::HIT},   {7, 9, PerfectBlackjack::HIT},   {7, 10, PerfectBlackjack::HIT},
    {6, 2, PerfectBlackjack::HIT},   {6, 3, PerfectBlackjack::HIT},   {6, 4, PerfectBlackjack::HIT}, {6, 5, PerfectBlackjack::HIT}, {6, 6, PerfectBlackjack::HIT}, {6, 7, PerfectBlackjack::HIT},   {6, 8, PerfectBlackjack::HIT},   {6, 9, PerfectBlackjack::HIT},   {6, 10, PerfectBlackjack::HIT},
    {5, 2, PerfectBlackjack::HIT},   {5, 3, PerfectBlackjack::HIT},   {5, 4, PerfectBlackjack::HIT}, {5, 5, PerfectBlackjack::HIT}, {5, 6, PerfectBlackjack::HIT}, {5, 7, PerfectBlackjack::HIT},   {5, 8, PerfectBlackjack::HIT},   {5, 9, PerfectBlackjack::HIT},   {5, 10, PerfectBlackjack::HIT},
};
}
namespace Casino {

bool PerfectBlackjack::EvenMoney(Hand& hand, Card::Ptr dealer)
{
    return false;
}

bool PerfectBlackjack::Insurance(Hand& hand, Card::Ptr dealer)
{
    return false;
}

bool PerfectBlackjack::Split(Hand& hand, Card::Ptr dealer)
{
    return true;
}

bool PerfectBlackjack::DoubleDown(Hand& hand, Card::Ptr dealer)
{
    return anyOnAction(hand, dealer, PerfectBlackjack::DOUBLE);
}
bool PerfectBlackjack::Hit(Hand& hand, Card::Ptr dealer)
{
    return anyOnAction(hand, dealer, PerfectBlackjack::HIT);
}

bool PerfectBlackjack::anyOnAction(Hand& hand, Card::Ptr dealer, ExpectedAction action) const
{
    return std::any_of(begin(perfectActions), end(perfectActions), [&](PerfectStragetyAction i){return i.playersValue == hand.Value() && i.dealersValue == dealer->Rank() && i.action==action;});
}

}
