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

#include "Outcome.hpp"
#include <string>
#include <memory>
using namespace std;

namespace game {
    class Bet {
    public:
        Bet();
        Bet (intmax_t Amount, Outcome odds);
        virtual ~Bet ();
        virtual intmax_t WinAmount() const;
        virtual intmax_t LoseAmount() const;
        virtual string ToString() const;

    private:
        intmax_t amount_;
        Outcome outcome_;
    };
    
} /* game */

#endif /* end of include guard: _BET */
