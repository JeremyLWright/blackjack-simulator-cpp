/**
 * @brief Provides the Player interface for a blackjack Casino
 *
 * @par
 * Copyright Jeremy Wright (c) 2012 
 * Creative Commons Attribution-ShareAlike 3.0 Unported License.
 */
#ifndef _BLACKJACKPLAYER
#define _BLACKJACKPLAYER

#include "Table.hpp"
#include "Bet.hpp"
#include "Hand.hpp"
#include "PlayerView.hpp"
#include <stdexcept>


namespace Casino {
    class BlackjackPlayer {
    public:
        /**
         * Initialize a player without a view
         */
        explicit BlackjackPlayer ();

        /**
         * Initialize a player with the given view
         */
        BlackjackPlayer(PlayerView* view);
        virtual ~BlackjackPlayer ();

        /**
         * Initialize a new game by:
         * - incrementing the round count.
         * - Clearing all the player's hands
         * - Create a new hand and give it to the player
         */
        virtual void NewGame();

        /**
         * Return the first hand.
         */
        virtual Hand::Ptr GetFirstHand() const;

        /**
         * Does the player wish to continue playing? i.e. Does he have enough
         * money to continue?
         */
        virtual bool IsPlaying() const;

        /**
         * Play a bet for all hands the player holds. If the Player is our of
         * money, throw Casino::OutOfMoneyException
         *
         * If the player has a view, request the correct amount from the view.
         */
        virtual void PlaceBets();

        /** 
         * Alert the player's view that he has won the game.
         */
        virtual void Win(Bet const & bet);

        /**
         * Alert the player's view that he has lose the game.
         */
        virtual void Lose(Bet const & bet);

        /**
         * Ask the player's view if he wishes to accept even money.
         */
        virtual bool EvenMoney(Hand& hand) const;

        /**
         * Ask the player's view if he wishes to accept Insurance.
         */
        virtual bool Insurance(Hand& hand) const;

        /**
         * Ask the player's view if he wishes to split the hand, if he does,
         * then create a new hand with the split, and return the new hand.
         */
        virtual Hand::Ptr Split(Hand& hand) ;

        /**
         * Ask the players view if he wishes to double down.
         */
        virtual bool DoubleDown(Hand& hand) const;

        /**
         * Ask the player's view if he wishes to Hit or Stand.
         */
        virtual bool Hit(Hand& hand) const;

        /**
         * Add money to the player's wallet i.e. mortgage the house to a loan
         * shark.
         */
		virtual void AddMoney(double dollars);

        /**
         * Return a reference to the player's view.
         */
        virtual PlayerView* GetView();

        /**
         * Send the player's view a reference of the dealer's up card.
         */
        virtual void DealerUpCard(Card::Ptr card);

        /**
         * Return a begin iterator to the players hands.
         */
        virtual vector<Hand::Ptr>::iterator begin();

        /** 
         * Return an end iterator to the players hands.
         */
        virtual vector<Hand::Ptr>::iterator end();

        /**
         * Sit this player at the given table.
         */
		virtual void SetTable(Table::Ptr table);
    protected:
        double stake_;
        int currentRound_;
        int roundsToGo_;
        Table::Ptr table_;
        vector<Hand::Ptr> hands_;
        PlayerView* view_;
    };
    
    struct OutOfMoneyException : public std::logic_error
    {
        OutOfMoneyException(BlackjackPlayer* player):
            logic_error("Player is out of money"),
            player_(player)
        {
        }
        BlackjackPlayer* player_;
    };
    
} /* Casino */

#endif /* end of include guard: _BLACKJACKPLAYER */
