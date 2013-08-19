/**
 * @brief Abstraction for a Hand of Blackjack
 *
 * @par
 * Copyright Jeremy Wright (c) 2012 
 * Creative Commons Attribution-ShareAlike 3.0 Unported License.
 */
#ifndef _HAND
#define _HAND

#include <vector>
#include <memory>
#include "Bet.hpp"
#include "Card.hpp"
namespace Casino {

    using namespace std;
    class BlackjackPlayer;
    /** \brief Simple container to store cards and their associated bet
     * referenced to a BlackjackPlayer \ref assign3
     */
    class Hand {
        public:
            typedef Hand* Ptr;
            Hand (BlackjackPlayer*);
            Hand():
                player_(nullptr)
            {
            }
            virtual ~Hand ();
            /** Add this card to the player's hand */
            void Add(Card::Ptr card);
            /** Add an ace card to the player's hand */
            void Add(AceCard::Ptr card);

            /** Return the value of the hand respecting hard and soft values */
            int Value() const;

            /** Return the size of the hand */
            int Size() const;

            /** Return true if the hand is a blackjack i.e 2 cards that equal
             * 21.
             */
            bool Blackjack() const;

            /**
             * Return true if the Value is > 21
             */
            bool Busted() const;

            /** Set the bet for this hand.
             */
            void SetBet(Bet& ante);
            BlackjackPlayer* GetPlayer() const;

            /** True if the hand is a pair. */
            bool Splittable();

            /** Once Split is declined do not ask the player again. */
            bool SplitDeclined() const;
            Bet& GetBet() const;

            /** REturn the up card. */
            Card::Ptr GetUpCard() const;
            vector<Card::Ptr>::const_iterator begin();
            vector<Card::Ptr>::const_iterator end();

        private:
            int aceCount_; ///< Hint... keeping the aceCount helps calculate the Value()...
            bool splitDeclined_;
            vector<Card::Ptr> cards_;
            Bet* ante_;
            BlackjackPlayer* player_;
    };

} /* Casino */

#endif /* end of include guard: _HAND */
