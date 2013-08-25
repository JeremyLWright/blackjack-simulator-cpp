#include "PlayerView.hpp"
using namespace std;
using namespace Casino;

PlayerView::PlayerView ()
{
}
PlayerView::~PlayerView ()
{
}
void PlayerView::ReceivedCardEvent(Card::Ptr card)
{
}
bool PlayerView::Hit(Hand& hand)
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
double PlayerView::GetBet(double available)
{
    return 1;
}
void PlayerView::Win(double amount)
{

}
void PlayerView::Lose()
{
}
void PlayerView::DealerBusted()
{
}
void PlayerView::FinalScore(int dealerScore, int playerScore)
{

}
void PlayerView::DealerUpCard(Card::Ptr card)
{
}


ConsoleView::ConsoleView ()
{
}
ConsoleView::~ConsoleView()
{
}
void ConsoleView::ReceivedCardEvent(Card::Ptr card)
{
    cout << "Received Card: " << card->ToString() << endl;
}
bool ConsoleView::Hit(Hand& hand)
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
double ConsoleView::GetBet(double available)
{
    auto betAmount = 1;
    cout << "Betting $" << betAmount << " of " << available << endl;

}
void ConsoleView::Win(double amount)
{
    cout << "you won: " << amount << endl;
}
void ConsoleView::Lose()
{
    cout << "You Lost: "  << endl;
}
void ConsoleView::DealerBusted()
{
    cout << "Dealer Busted - Everyone Wins." << endl;
}
void ConsoleView::FinalScore(int dealerScore, int playerScore)
{

    cout << "Dealer Got " << dealerScore << " you got " << playerScore << "." << endl;
}


/** \brief View to a perfect stragety for automated play testing
 * \ref assign7
 */
PerfectView::PerfectView ()
{
    wins = 0;
    losses = 0;
    strat = new PerfectBlackjack();
}
PerfectView::~PerfectView()
{
}
void PerfectView::ReceivedCardEvent(Card::Ptr card)
{
    cout << "Received Card: " << card->ToString() << endl;
}
bool PerfectView::Hit(Hand& hand)
{
    return strat->Hit(hand, _card);
}
double PerfectView::GetBet(double available)
{
    auto betAmount = 15;
    cout << "Betting $" << betAmount << " of " << available << endl;

}
void PerfectView::Win(double amount)
{
    wins += 1;
    cout << "Winner";
    cout << wins << " and " << losses << endl;
}
void PerfectView::Lose()
{
    losses += 1;
    cout << wins << " and " << losses << endl;
}
void PerfectView::DealerBusted()
{
    cout << "Dealer Busted - Everyone Wins." << endl;
}
void PerfectView::FinalScore(int dealerScore, int playerScore)
{
    cout << "Dealer Got " << dealerScore << " you got " << playerScore << "." << endl;
}
void PerfectView::DealerUpCard(Card::Ptr card)
{
    _card = card;
}

double PerfectView::GetWinRatio()
{
    return (wins / (wins + losses))*100;
}

