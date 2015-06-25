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

namespace Casino {

    struct TableLimitException : public std::logic_error
    {
        TableLimitException(double currentBetAmount, double currentCosts, int tableLimit);
        virtual char const * what() const throw();
        double betAmount_;
        double tableCost_;
        int tableLimit_;

    };
    /** \brief container for bets and a reference to the players at tht table.
     * \ref assign6 */
    class Table {
    public:
		typedef Table* Ptr;
        /** Initialize a table with the given limit, default to 1000 */
        Table (int limit=1000);
        virtual ~Table ();

        /** Place a bet on the table, essure the bet does not exceed the table
         * limit.
         */
        void PlaceBet(Bet* bet, Hand* hand);

        /** Initialize a new game by clearing all the bets.
         */
        void NewGame();

        /** 
         * Verify a bet is valid against the table limit.
         */
        bool IsValid(Bet& bet) const;
        string ToString() const;
    private:
        int limit_;
        vector<Bet*> bets_;
        double Cost() const;
    };
    
} /* Casino */

#endif /* end of include guard: _TABLE */
