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
namespace Casino {
    class Odds {
    public:
        Odds (string Name, pair<int, int> Odds);
        virtual ~Odds();
        friend int operator*(Odds const & lhs, int Amount);
        friend int operator*(int Amount, Odds const & rhs);
        
        bool operator==(Odds const & rhs) const;
        bool operator!=(Odds const & rhs) const;
        
        string ToString() const;

    private:
        string name_;
        pair<int, int> odds_;

    };

    
} /* Casino */

#endif /* end of include guard: _OUTCOME */
