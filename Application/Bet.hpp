/**
 * @brief Bet class for determining the outcome of a bet associated with
 * a player
 *
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
    class Bet {
    public:
        Bet();
        Bet (double Amount, Odds odds);
        virtual ~Bet ();
        virtual double WinAmount() const;
        virtual double LoseAmount() const;
        virtual string ToString() const;

    private:
        double amount_;
        Odds outcome_;
    };
    
} /* Casino */

#endif /* end of include guard: _BET */
