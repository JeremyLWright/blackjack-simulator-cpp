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
    class Hand {
        public:
            typedef Hand* Ptr;
            explicit Hand (BlackjackPlayer&);
            virtual ~Hand ();
            void Add(Card::Ptr card);
            void Add(AceCard::Ptr card);
            int Value() const;
            int Size() const;
            bool Blackjack() const;
            bool Busted() const;
            void SetBet(Bet& ante);
            BlackjackPlayer& GetPlayer() const;
            bool Splittable();
            bool SplitDeclined() const;
            Bet& GetBet() const;
            Card::Ptr GetUpCard() const;
            vector<Card::Ptr>::const_iterator begin();
            vector<Card::Ptr>::const_iterator end();

        private:
            int aceCount_;
            bool splitDeclined_;
            vector<Card::Ptr> cards_;
            Bet* ante_;
            BlackjackPlayer& player_;
    };

} /* Casino */

#endif /* end of include guard: _HAND */
