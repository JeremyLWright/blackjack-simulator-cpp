#ifndef BETTINGSTRAGETY_H
#define BETTINGSTRAGETY_H

#include "Hand.hpp"
#include "Card.hpp"
namespace Casino {
class BettingStragety {
    public:
    virtual bool EvenMoney(Hand& hand, Card::Ptr dealer) const = 0;
    virtual bool Insurance(Hand& hand, Card::Ptr dealer) const = 0;
    virtual bool Split(Hand& hand, Card::Ptr dealer) const = 0;
    virtual bool DoubleDown(Hand& hand, Card::Ptr dealer) const = 0;
    virtual bool Hit(Hand& hand, Card::Ptr dealer) const = 0;
};

class HumanPlayer : public BettingStragety {

};

class PerfectBlackjack : public BettingStragety {
    /*
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
        return true;
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
        return true;
    }
    virtual bool Hit(Hand& hand, Card::Ptr dealer) const
    {
        return true;
    }

};

}
#endif /* end of include guard: BETTINGSTRAGETY_H */
