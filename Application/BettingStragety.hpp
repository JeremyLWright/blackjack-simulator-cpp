#ifndef BETTINGSTRAGETY_H
#define BETTINGSTRAGETY_H

#include "Hand.hpp"
#include "Card.hpp"
#include <algorithm>
namespace Casino {
class BettingStragety {
    public:

    /**
     * Does the player choose EvenMoney?
     */
    virtual bool EvenMoney(Hand& hand, Card::Ptr dealer) const = 0;

    /** 
     * Does the player want insurance?
     */
    virtual bool Insurance(Hand& hand, Card::Ptr dealer) const = 0;

    /**
     * Does the Player want to split the hand (offered for doubles)?
     */
    virtual bool Split(Hand& hand, Card::Ptr dealer) const = 0;

    /**
     * Does the player want to double down?
     */
    virtual bool DoubleDown(Hand& hand, Card::Ptr dealer) const = 0;

    /** 
     * Does the player want to hit, or stand?
     */
    virtual bool Hit(Hand& hand, Card::Ptr dealer) const = 0;
};

class PerfectBlackjack : public BettingStragety {
    /* The following are the decisions to play statistically perfect blackjack.
     * Source: wikipedia.org
Player hand 	Dealer's face-up card
                2 	3 	4 	5 	6 	7 	8 	9 	10 	A
                Hard totals (excluding pairs)
    17–20       S 	S 	S 	S 	S 	S 	S 	S 	S 	S
    16          S 	S 	S 	S 	S 	H 	H 	SU 	SU 	SU
    15          S 	S 	S 	S 	S 	H 	H 	H 	SU 	H
    13–14       S 	S 	S 	S 	S 	H 	H 	H 	H 	H
    12          H 	H 	S 	S 	S 	H 	H 	H 	H 	H
    11          Dh 	Dh 	Dh 	Dh 	Dh 	Dh 	Dh 	Dh 	Dh 	H
    10          Dh 	Dh 	Dh 	Dh 	Dh 	Dh 	Dh 	Dh 	H 	H
    9           H 	Dh 	Dh 	Dh 	Dh 	H 	H 	H 	H 	H
    5–8         H 	H 	H 	H 	H 	H 	H 	H 	H 	H
                    Soft totals
                2 	3 	4 	5 	6 	7 	8 	9 	10 	A
    A,8–A,9 	S 	S 	S 	S 	S 	S 	S 	S 	S 	S
    A,7         S 	Ds 	Ds 	Ds 	Ds 	S 	S 	H 	H 	H
    A,6         H 	Dh 	Dh 	Dh 	Dh 	H 	H 	H 	H 	H
    A,4–A,5 	H 	H 	Dh 	Dh 	Dh 	H 	H 	H 	H 	H
    A,2–A,3 	H 	H 	H 	Dh 	Dh 	H 	H 	H 	H 	H
                        Pairs
                2 	3 	4 	5 	6 	7 	8 	9 	10 	A
    A,A         SP 	SP 	SP 	SP 	SP 	SP 	SP 	SP 	SP 	SP
    10,10       S 	S 	S 	S 	S 	S 	S 	S 	S 	S
    9,9         SP 	SP 	SP 	SP 	SP 	S 	SP 	SP 	S 	S
    8,8         SP 	SP 	SP 	SP 	SP 	SP 	SP 	SP 	SP 	SP
    7,7         SP 	SP 	SP 	SP 	SP 	SP 	H 	H 	H 	H
    6,6         SP 	SP 	SP 	SP 	SP 	H 	H 	H 	H 	H
    5,5         Dh 	Dh 	Dh 	Dh 	Dh 	Dh 	Dh 	Dh 	H 	H
    4,4         H 	H 	H 	SP 	SP 	H 	H 	H 	H 	H
    2,2–3,3     SP 	SP 	SP 	SP 	SP 	SP 	H 	H 	H 	H
Key:
    S = Stand
    H = Hit
    Dh = Double (if not allowed, then hit)
    Ds = Double (if not allowed, then stand)
    SP = Split
    SU = Surrender (if not allowed, then hit.) 
*/
    public:

    virtual bool EvenMoney(Hand& hand, Card::Ptr dealer) const
    {
        return false;
    }
    virtual bool Insurance(Hand& hand, Card::Ptr dealer) const
    {
        return false;
    }
    virtual bool Split(Hand& hand, Card::Ptr dealer) const
    {
        return true;
    }
    virtual bool DoubleDown(Hand& hand, Card::Ptr dealer) const
    {
        return anyOnAction(hand, dealer, DOUBLE);
    }
    virtual bool Hit(Hand& hand, Card::Ptr dealer) const
    {
        return anyOnAction(hand, dealer, HIT);
    }

    private:
     enum ExpectedAction {
        STAND,
        HIT,
        DOUBLE,
        SPLIT
    };

    bool anyOnAction(Hand& hand, Card::Ptr dealer, ExpectedAction action) const
    {
        return std::any_of(begin(perfectActions), end(perfectActions), [&](PerfectStragetyAction i){return i.playersValue == hand.Value() && i.dealersValue == dealer->Rank() && i.action==action;});
    }

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


};

}
#endif /* end of include guard: BETTINGSTRAGETY_H */
