#ifndef BETTINGSTRAGETY_H
#define BETTINGSTRAGETY_H

#include "Hand.hpp"
#include "Card.hpp"
#include <algorithm>
namespace Casino {
    /** 
     * \brief Sets up a stragety to automate player decisions. Or defer decision to
     * an actual player i.e. console commands
     * \ref assign7
     */
class BettingStragety {
    public:

    /**
     * Does the player choose EvenMoney?
     */
    virtual bool EvenMoney(Hand& hand, Card::Ptr dealer)  = 0;

    /** 
     * Does the player want insurance?
     */
    virtual bool Insurance(Hand& hand, Card::Ptr dealer)  = 0;

    /**
     * Does the Player want to split the hand (offered for doubles)?
     */
    virtual bool Split(Hand& hand, Card::Ptr dealer)  = 0;

    /**
     * Does the player want to double down?
     */
    virtual bool DoubleDown(Hand& hand, Card::Ptr dealer)  = 0;

    /** 
     * Does the player want to hit, or stand?
     */
    virtual bool Hit(Hand& hand, Card::Ptr dealer)  = 0;
};

/**
 * \brief Example stragety for playing perfect blackjack. \ref assign7
 */
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

    virtual bool EvenMoney(Hand& hand, Card::Ptr dealer);
    virtual bool Insurance(Hand& hand, Card::Ptr dealer);
    virtual bool Split(Hand& hand, Card::Ptr dealer);
    virtual bool DoubleDown(Hand& hand, Card::Ptr dealer);
    virtual bool Hit(Hand& hand, Card::Ptr dealer);
    
    enum ExpectedAction {
        STAND,
        HIT,
        DOUBLE,
        SPLIT
    };

    private:

    bool anyOnAction(Hand& hand, Card::Ptr dealer, ExpectedAction action) const;

};

}
#endif /* end of include guard: BETTINGSTRAGETY_H */
