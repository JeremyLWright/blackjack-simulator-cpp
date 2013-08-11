#include "BlackjackPlayer.hpp"
#include "Table.hpp"
#include <memory>
#include <iostream>
using namespace std;

namespace Casino {
    BlackjackPlayer::BlackjackPlayer():
        stake_(0),
        currentRound_(0),
        roundsToGo_(0)
    {
        view_ = new PlayerView();
    }

    BlackjackPlayer::BlackjackPlayer(PlayerView* view):
        stake_(0),
        currentRound_(0),
        roundsToGo_(0),
        view_(view)
    {
    }

    BlackjackPlayer::~BlackjackPlayer()
    {
    }
    
    void BlackjackPlayer::NewGame()
    {
        currentRound_++;
        hands_.clear();
        auto h = new Hand(this);
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
			if(stake_ <= 0)
				throw logic_error("Player is out of money.");
            auto betAmount = view_->GetBet(stake_);
            stake_ -= betAmount;
            auto bet = new Bet(betAmount, Odds("Jeremy's Bet", make_pair(3,2)));
            table_->PlaceBet(bet, hand);
        }
    }

    void BlackjackPlayer::Win(Bet const & bet)
    {
        view_->Win(bet.WinAmount());
        stake_ += bet.WinAmount();
    }

    void BlackjackPlayer::Lose(Bet const & bet)
    {
        //We already deducted our money
        view_->Lose();
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
        auto splitHand = new Hand(this);
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
        return view_->Hit(hand);
    }

    PlayerView* BlackjackPlayer::GetView()
    {
        return view_;
    }

	void BlackjackPlayer::AddMoney(int dollars)
	{
		stake_ += dollars;
	}

    vector<Hand::Ptr>::iterator BlackjackPlayer::begin()
    {
        return std::begin(hands_);
    }

    vector<Hand::Ptr>::iterator BlackjackPlayer::end()
    {
        return std::end(hands_);
    }

	void BlackjackPlayer::SetTable(Table::Ptr table)
	{
		table_ = table;
	}



} /* Casino */
