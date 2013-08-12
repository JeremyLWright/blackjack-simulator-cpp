/**
 * @brief Top-level Casino which runs Blackjack
 *
 * @par
 * Copyright Jeremy Wright (c) 2012 
 * Creative Commons Attribution-ShareAlike 3.0 Unported License.
 */
#ifndef _BLACKJACKGAME
#define _BLACKJACKGAME

#include <string>
#include <vector>
#include "BlackjackPlayer.hpp"
#include "Shoe.hpp"
#include "Table.hpp"
#include "Hand.hpp"
using namespace std;
namespace Casino {
    class BlackjackGame {
    public:
        /**
         * - Adds Money to the dealer
         * - Sets the Dealer to the Table
         */
        BlackjackGame (Shoe& shoe, Table::Ptr table);
        virtual ~BlackjackGame ();
        virtual void AddPlayer(BlackjackPlayer* player);
        /**
         * This method runs through an entire game cycle.
         * - Shuffle the deck
         * - Initialize Each Player
         * - Initialize the Dealer
         * - Get the dealer's first hand
                - Offer Insurance if applicable
         * - For each Player
                - And each hand the player has
         * - Offer to split the hand if available
         * - For Each player
                - And each hand the player has
         * - Fill the hand with cards
         * - Fill the dealer's hand
         * - If the dealer busted
                - For each player
         * - And each hand the player has
         * - Resolve the hand as a winner
         * - Otherwise
         * - For each player
                - And each hand the player has
         * - If the player busted
         * - Signal Player Lost
         * - Otherwise if the player beat the dealer
         * - Signal Player Win
         * - Otherwise
         * - Signal Player Lost
        */
        virtual void Cycle();

        /**
         * Offer insurance to the player if the dealer's upcard is an Ace or if
         * the player has Blackjack. Insurance makes a 2:1 bet (rather than 3:2)
         */
        virtual void Insurance();

        /**
         * Fill the hand until the player chooses the stand, or the player busts
         */
        virtual void FillHand(Hand& hand);
        virtual string ToString();
    private:
        /**
         * - Signals the plauer is starting a new game
         * - Load the player's hands with 2 cards
         * - Let the player place bets
         */
        void InitPlayer(BlackjackPlayer& player);
        Shoe& shoe_;
        Table::Ptr table_;
        BlackjackPlayer dealer_;
        vector<BlackjackPlayer*> players_;
    };
    
} /* BlackjackGame */

#endif /* end of include guard: _BLACKJACKGAME */
