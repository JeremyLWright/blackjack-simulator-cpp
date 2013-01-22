/**
 * @brief Class representing the Blackjack table's responsibilities
 *
 * @par
 * Copyright Jeremy Wright (c) 2012 
 * Creative Commons Attribution-ShareAlike 3.0 Unported License.
 */
#ifndef _TABLE
#define _TABLE

#include "BlackjackPlayer.hpp"
#include "Bet.hpp"
#include "Hand.hpp"
#include <string>
#include <vector>
#include <memory>
#include <stdexcept>

using namespace std;

namespace Casino {

    struct TableLimitException : public std::logic_error
    {
        TableLimitException(int currentBetAmount, int currentCosts, int tableLimit);
        virtual char const * what() const throw();
        int betAmount_;
        int tableCost_;
        int tableLimit_;

    };

    class Table {
    public:
        Table (int limit=1000);
        virtual ~Table ();
        void PlaceBet(Bet* bet, Hand* hand);
        bool IsValid(Bet& bet) const;
        void AddPlayer(BlackjackPlayer* player);
        string ToString() const;
    private:
        int limit_;
        vector<BlackjackPlayer*> players_;
        vector<Bet*> bets_;
        int Cost() const;
    };
    
} /* Casino */

#endif /* end of include guard: _TABLE */
