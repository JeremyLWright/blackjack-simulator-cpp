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
        BlackjackGame (Shoe& shoe, Table::Ptr table);
        virtual ~BlackjackGame ();
        virtual void AddPlayer(BlackjackPlayer* player);
        virtual void Cycle();
        virtual void Insurance();
        virtual void FillHand(Hand& hand);
        virtual string ToString();
    private:
        void InitPlayer(BlackjackPlayer& player);
        Shoe& shoe_;
        Table::Ptr table_;
        BlackjackPlayer dealer_;
        vector<BlackjackPlayer*> players_;
    };
    
} /* BlackjackGame */

#endif /* end of include guard: _BLACKJACKGAME */
