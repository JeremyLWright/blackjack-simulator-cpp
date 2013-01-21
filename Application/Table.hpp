/**
 * @brief Class representing the Blackjack table's responsibilities
 *
 * @par
 * Copyright Jeremy Wright (c) 2012 
 * Creative Commons Attribution-ShareAlike 3.0 Unported License.
 */
#ifndef _TABLE
#define _TABLE

#include "Bet.hpp"
#include "Hand.hpp"
#include <string>
#include <vector>
#include <memory>
#include <stdexcept>

using namespace std;

namespace Game {

    struct TableLimitException : public std::logic_error
    {
        TableLimitException(intmax_t currentBetAmount, intmax_t currentCosts, intmax_t tableLimit);
        virtual char const * what() const throw();
        intmax_t betAmount_;
        intmax_t tableCost_;
        intmax_t tableLimit_;

    };

    class Table {
    public:
        Table (intmax_t limit=1000);
        virtual ~Table ();
        void PlaceBet(Bet& bet, Hand& hand);
        bool IsValid(Bet& bet) const;
        void AddPlayer();
        string ToString() const;
    private:
        intmax_t limit_;
        vector<Player*> _players;
        vector<shared_ptr<Bet>> bets_;
        intmax_t Cost() const;
    };
    
} /* game */

#endif /* end of include guard: _TABLE */
