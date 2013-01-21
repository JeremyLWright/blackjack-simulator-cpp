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
        Bet (int Amount, Odds odds);
        virtual ~Bet ();
        virtual int WinAmount() const;
        virtual int LoseAmount() const;
        virtual string ToString() const;

    private:
        int amount_;
        Odds outcome_;
    };
    
} /* Casino */

#endif /* end of include guard: _BET */
