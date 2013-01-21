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
namespace game {

    using namespace std;
    class Card;
    class AceCard;
    class BlackjackPlayer;
    class Hand {
        public:
            explicit Hand (BlackjackPlayer&);
            virtual ~Hand ();
            void Add(shared_ptr<Card> card);
            void Add(shared_ptr<AceCard> card);
            int Value() const;
            int Size() const;
            bool Blackjack() const;
            bool Busted() const;
            void SetBet(shared_ptr<Bet> ante);
            BlackjackPlayer& GetPlayer() const;
            bool Splittable();
            bool SplitDeclined() const;
            shared_ptr<Bet> GetBet() const;
            shared_ptr<Card> GetUpCard() const;
            vector<shared_ptr<Card>>::const_iterator begin();
            vector<shared_ptr<Card>>::const_iterator end();

        private:
            int aceCount_;
            bool splitDeclined_;
            vector<shared_ptr<Card>> cards_;
            shared_ptr<Bet> ante_;
            BlackjackPlayer& player_;
    };

} /* game */

#endif /* end of include guard: _HAND */
