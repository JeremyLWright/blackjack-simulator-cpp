#include "BlackjackPlayer.hpp"
#include <memory>

using namespace std;

namespace Casino {
    BlackjackPlayer::BlackjackPlayer(Table& table):
        stake_{0},
        currentRound_{0},
        roundsToGo_{0},
        table_(table)
    {
    }

    BlackjackPlayer::~BlackjackPlayer()
    {
    }
    
    void BlackjackPlayer::NewGame()
    {
        currentRound_++;
        hands_.clear();
        auto h = make_shared<Hand>(Hand(*this));
        hands_.push_back(h);
    }

    shared_ptr<Hand> BlackjackPlayer::GetFirstHand() const
    {
        return hands_[0];
    }

    bool BlackjackPlayer::IsPlaying() const
    {
        return (roundsToGo_-currentRound_ > 0 && stake_>=0);
    }

    void BlackjackPlayer::PlaceBets()
    {
        stake_ -= 1000;
        auto bet = Bet(1000, Outcome("Jeremy'sBet", make_pair(3,2)));
        table_.PlaceBet(move(bet), *hands_[0]);
    }

    void BlackjackPlayer::Win(Bet const & bet)
    {
        stake_ += bet.WinAmount();
    }

    void BlackjackPlayer::Lose(Bet const & bet)
    {
        //We already deducted our money
        return;
    }

    bool BlackjackPlayer::EvenMoney(Hand& hand) const
    {
        return false;
    }

    bool BlackjackPlayer::Insurance(Hand& hand) const
    {
        return false;
    }

    shared_ptr<Hand> BlackjackPlayer::Split(Hand& hand) 
    {
        auto splitHand = make_shared<Hand>(Hand(*this));
        auto splitBet = make_shared<Bet>(Bet(*hand.GetBet().get()));
        splitHand->SetBet(splitBet);
        hands_.push_back(splitHand);
        return splitHand;
    }

    bool BlackjackPlayer::DoubleDown(Hand& hand) const
    {
        return false;
    }

    bool BlackjackPlayer::Hit(Hand& hand) const
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

    vector<shared_ptr<Hand>>::iterator BlackjackPlayer::begin()
    {
        return std::begin(hands_);
    }

    vector<shared_ptr<Hand>>::iterator BlackjackPlayer::end()
    {
        return std::end(hands_);
    }





} /* Casino */
