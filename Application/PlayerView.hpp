#ifndef PLAYERVIEW_H
#define PLAYERVIEW_H

#include <iostream>
#include "Card.hpp"
#include "Hand.hpp"
#include "BettingStragety.hpp"
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
        virtual double GetBet(double available)
        {
            return 1;
        }
        virtual void Win(double amount)
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
        virtual void DealerUpCard(Card::Ptr card)
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
        virtual double GetBet(double available)
        {
            auto betAmount = 1;
			cout << "Betting $" << betAmount << " of " << available << endl;
 
        }
        virtual void Win(double amount)
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
    


    class PerfectView : public PlayerView {
    public:
        PerfectView ()
        {
            wins = 0;
            losses = 0;
            strat = new PerfectBlackjack();
        }
        virtual ~PerfectView()
        {
        }
        virtual void ReceivedCardEvent(Card::Ptr card)
        {
            cout << "Received Card: " << card->ToString() << endl;
        }
        virtual bool Hit(Hand& hand)
        {
            return strat->Hit(hand, _card);
        }
        virtual double GetBet(double available)
        {
            auto betAmount = 15;
			cout << "Betting $" << betAmount << " of " << available << endl;
 
        }
        virtual void Win(double amount)
        {
            wins += 1;
            cout << "Winner";
            cout << wins << " and " << losses << endl;
        }
        virtual void Lose()
        {
            losses += 1;
            cout << wins << " and " << losses << endl;
        }
        virtual void DealerBusted()
        {
			cout << "Dealer Busted - Everyone Wins." << endl;
        }
        virtual void FinalScore(int dealerScore, int playerScore)
        {
			cout << "Dealer Got " << dealerScore << " you got " << playerScore << "." << endl;
        }
        virtual void DealerUpCard(Card::Ptr card)
        {
            _card = card;
        }

        double GetWinRatio()
        {
            return (wins / (wins + losses))*100;
        }
    
    private:
        double wins;
        double losses;
        BettingStragety* strat; 
        Card::Ptr _card;
        /* data */
    };
    
    
} /* Casino */

#endif /* end of include guard: PLAYERVIEW_H */
