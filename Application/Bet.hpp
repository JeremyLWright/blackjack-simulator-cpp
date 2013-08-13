/**
 * @par
 * Copyright Jeremy Wright (c) 2012 
 * Creative Commons Attribution-ShareAlike 3.0 Unported License.
 */
#ifndef _BET
#define _BET

#include "Odds.hpp"
#include <string>
using namespace std;

namespace Casino {
    /**
     * Bet class for determining the outcome of a bet associated with
 * a player
     * \brief Abstracts a wager for the player to place on the table.
     * \ref assign4
     */
    class Bet {
    public:
        Bet();
        /**
         * Initialized the Odd amount
         * - Blackjack bets pay out 3:2
         * - Instance bets pay out 2:1
         * This is a generic class independent of the odds themselves.
         */
        Bet (double Amount, Odds odds);
        virtual ~Bet ();
        /** Calculate the amount won my the player, by multiplying the odds by
         * the amount wagered.
         */
        virtual double WinAmount() const;

        /** Calculate the amount lost by the player, typically just the wager
         * itself.
         */
        virtual double LoseAmount() const;
        virtual string ToString() const;

    private:
        double amount_;
        Odds outcome_;
    };
    
} /* Casino */

#endif /* end of include guard: _BET */
