/**
 * @brief Determins the result of a bet, for given odds
 *
 * @par
 * Copyright Jeremy Wright (c) 2012 
 * Creative Commons Attribution-ShareAlike 3.0 Unported License.
 */
#ifndef _OUTCOME
#define _OUTCOME

#include <string>
#include <sstream>
#include <ratio>
#include <utility>
using namespace std;
namespace game {
    class Outcome {
    public:
        Outcome (string Name, pair<intmax_t, intmax_t> Odds);
        virtual ~Outcome();
        friend int operator*(Outcome const & lhs, intmax_t Amount);
        friend int operator*(intmax_t Amount, Outcome const & rhs);
        
        bool operator==(Outcome const & rhs) const;
        bool operator!=(Outcome const & rhs) const;
        
        string ToString() const;

    private:
        string name_;
        pair<intmax_t, intmax_t> odds_;

    };

    
} /* game */

#endif /* end of include guard: _OUTCOME */
