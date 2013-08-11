#ifndef PLAYERVIEW_H
#define PLAYERVIEW_H

#include <iostream>
#include "Card.hpp"
#include "Hand.hpp"
using namespace std;

namespace Casino {
    class PlayerView {
    public:
        PlayerView ()
        {
        }
        virtual ~PlayerView ()
        {
        }
        virtual void ReceivedCardEvent(Card::Ptr card)
        {
        }
        virtual bool Hit(Hand& hand)
        {
            if(hand.Value() >= 17)
            {
                return false;
            }
            else 
            {
                return true;
            }
        }
        virtual int GetBet(int available)
        {
            return 1;
        }
        virtual void Win(int amount)
        {

        }
        virtual void Lose()
        {
        }
        virtual void DealerBusted()
        {
        }
        virtual void FinalScore(int dealerScore, int playerScore)
        {

        }
    private:
        /* data */
    };

    class ConsoleView : public PlayerView {
    public:
        ConsoleView ();
        virtual ~ConsoleView();
        virtual void ReceivedCardEvent(Card::Ptr card)
        {
            cout << "Received Card: " << card->ToString() << endl;
        }
        virtual bool Hit(Hand& hand)
        {
            if(hand.Value() >= 17)
            {
                cout << "Stand." << endl;
                return false;
            }
            else 
            {
                cout << "Hit Me." << endl;
                return true;
            }

        }
        virtual int GetBet(int available)
        {
            auto betAmount = 1;
			cout << "Betting $" << betAmount << " of " << available << endl;
 
        }
        virtual void Win(int amount)
        {
            	cout << "you won: " << amount << endl;
        }
        virtual void Lose()
        {
		    cout << "You Lost: "  << endl;
        }
        virtual void DealerBusted()
        {
			cout << "Dealer Busted - Everyone Wins." << endl;
        }
        virtual void FinalScore(int dealerScore, int playerScore)
        {

			cout << "Dealer Got " << dealerScore << " you got " << playerScore << "." << endl;
        }
    
    private:
        /* data */
    };
    

    
} /* Casino */

#endif /* end of include guard: PLAYERVIEW_H */
