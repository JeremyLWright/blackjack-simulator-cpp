/**
 * @brief Provides the Player interface for a blackjack game
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

namespace game {
    class BlackjackPlayer {
    public:
        explicit BlackjackPlayer (Table& table);
        virtual ~BlackjackPlayer ();
        void NewGame();
        shared_ptr<Hand> GetFirstHand() const;
        virtual bool IsPlaying() const;
        virtual void PlaceBets();
        virtual void Win(Bet const & bet);
        virtual void Lose(Bet const & bet);

        virtual bool EvenMoney(Hand& hand) const;
        virtual bool Insurance(Hand& hand) const;
        virtual shared_ptr<Hand> Split(Hand& hand) ;
        virtual bool DoubleDown(Hand& hand) const;
        virtual bool Hit(Hand& hand) const;

        vector<shared_ptr<Hand>>::iterator begin();
        vector<shared_ptr<Hand>>::iterator end();
    private:
        intmax_t stake_;
        intmax_t currentRound_;
        intmax_t roundsToGo_;
        Table& table_;
        vector<shared_ptr<Hand>> hands_;
    };
    
} /* game */

#endif /* end of include guard: _BLACKJACKPLAYER */
