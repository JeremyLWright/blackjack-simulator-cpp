#ifndef PLAYERVIEW_H
#define PLAYERVIEW_H

#include <iostream>
#include "Card.hpp"
#include "Hand.hpp"
#include "BettingStragety.hpp"
using namespace std;

namespace Casino {
    /** \brief interface to a real life player, or an automated stragety \ref
     * assign7 */
    class PlayerView {
    public:
        PlayerView ();
        virtual ~PlayerView ();
        virtual void ReceivedCardEvent(Card::Ptr card);
        virtual bool Hit(Hand& hand);
        virtual double GetBet(double available);
        virtual void Win(double amount);
        virtual void Lose();
        virtual void DealerBusted();
        virtual void FinalScore(int dealerScore, int playerScore);
        virtual void DealerUpCard(Card::Ptr card);
    private:
        /* data */
    };

    /** \brief View to cout/cin command to interace with a real person \ref
     * assign7 */
    class ConsoleView : public PlayerView {
    public:
        ConsoleView ();
        virtual ~ConsoleView();
        virtual void ReceivedCardEvent(Card::Ptr card);
        virtual bool Hit(Hand& hand);
        virtual double GetBet(double available);
        virtual void Win(double amount);
        virtual void Lose();
        virtual void DealerBusted();
        virtual void FinalScore(int dealerScore, int playerScore);
    
    private:
        /* data */
    };
    

    /** \brief View to a perfect stragety for automated play testing
     * \ref assign7
     */
    class PerfectView : public PlayerView {
    public:
        PerfectView ();
        virtual ~PerfectView();
        virtual void ReceivedCardEvent(Card::Ptr card);
        virtual bool Hit(Hand& hand);
        virtual double GetBet(double available);
        virtual void Win(double amount);
        virtual void Lose();
        virtual void DealerBusted();
        virtual void FinalScore(int dealerScore, int playerScore);
        virtual void DealerUpCard(Card::Ptr card);

        double GetWinRatio();
    
    private:
        double wins;
        double losses;
        BettingStragety* strat; 
        Card::Ptr _card;
        /* data */
    };
    
    
} /* Casino */

#endif /* end of include guard: PLAYERVIEW_H */
