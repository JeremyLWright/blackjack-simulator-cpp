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
        Odds (string Name, pair<double, double> Odds);
        virtual ~Odds();

        /**  Multiple operator for the odds and a number */
        friend double operator*(Odds const & lhs, double Amount);
        /**  Multiple operator for the odds and a number */
        friend double operator*(double Amount, Odds const & rhs);
        
        bool operator==(Odds const & rhs) const;
        bool operator!=(Odds const & rhs) const;
        
        string ToString() const;

    private:
        string name_;
        pair<double, double> odds_;

    };

    
} /* Casino */

#endif /* end of include guard: _OUTCOME */
