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


namespace Casino {
    class BlackjackPlayer {
    public:
        explicit BlackjackPlayer ();
        BlackjackPlayer(PlayerView* view);
        virtual ~BlackjackPlayer ();
        virtual void NewGame();
        virtual Hand::Ptr GetFirstHand() const;
        virtual bool IsPlaying() const;
        virtual void PlaceBets();
        virtual void Win(Bet const & bet);
        virtual void Lose(Bet const & bet);

        virtual bool EvenMoney(Hand& hand) const;
        virtual bool Insurance(Hand& hand) const;
        virtual Hand::Ptr Split(Hand& hand) ;
        virtual bool DoubleDown(Hand& hand) const;
        virtual bool Hit(Hand& hand) const;
		virtual void AddMoney(int dollars);
        virtual PlayerView* GetView();

        virtual vector<Hand::Ptr>::iterator begin();
        virtual vector<Hand::Ptr>::iterator end();
		virtual void SetTable(Table::Ptr table);
    private:
        int stake_;
        int currentRound_;
        int roundsToGo_;
        Table::Ptr table_;
        vector<Hand::Ptr> hands_;
        PlayerView* view_;
    };
    
} /* Casino */

#endif /* end of include guard: _BLACKJACKPLAYER */
