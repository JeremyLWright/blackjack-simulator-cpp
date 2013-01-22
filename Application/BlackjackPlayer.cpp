#include "BlackjackPlayer.hpp"
#include "Table.hpp"
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
        auto h = new Hand(*this);
        hands_.push_back(h);
    }

    Hand::Ptr BlackjackPlayer::GetFirstHand() const
    {
        return hands_[0];
    }

    bool BlackjackPlayer::IsPlaying() const
    {
        return (roundsToGo_-currentRound_ > 0 && stake_>=0);
    }

    void BlackjackPlayer::PlaceBets()
    {
        for(auto hand : hands_)
        {
            stake_ -= 1000;
            auto bet = new Bet(1000, Odds("Jeremy's Bet", make_pair(3,2)));
            table_.PlaceBet(bet, hand);
        }
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

    Hand::Ptr BlackjackPlayer::Split(Hand& hand) 
    {
        auto splitHand = new Hand(*this);
        auto splitBet = new Bet(hand.GetBet());
        splitHand->SetBet(*(splitBet));
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

    vector<Hand::Ptr>::iterator BlackjackPlayer::begin()
    {
        return std::begin(hands_);
    }

    vector<Hand::Ptr>::iterator BlackjackPlayer::end()
    {
        return std::end(hands_);
    }





} /* Casino */
