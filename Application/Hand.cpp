#include <vector>
#include <iostream>
#include <memory>
#include <algorithm>
#include "Card.hpp"
#include "Hand.hpp"

using namespace std;

namespace Casino {
    Hand::Hand(BlackjackPlayer& player):
#if __GNUC__
        aceCount_{0},
#else
		  aceCount_(0),
#endif
        player_(player)
    {
    }

    Hand::~Hand()
    {
    }

    void Hand::Add(Card::Ptr card)
    {
		cout << "Received Card: " << card->ToString() << endl;
        cards_.push_back(card);
    }
    
    void Hand::Add(AceCard::Ptr card)
    {
		cout << "Received Card: " << card->ToString() << endl;
        cards_.push_back(card);
        aceCount_++;
    }

    int Hand::Value() const
    {
#if __GNUC__
        int total{0};
#else
		  int total = 0;
#endif
        for(auto card : cards_)
        {
            total += card->SoftValue();
        }        
        
        //All card have contributed their minimum, now try to bump up the
        //score by adding hard delta from the Ace
        for(int i = 0; i < aceCount_; ++i)
        {
            if(total + 10 > 21)
                break;
            else
                total += 10;
        }

        return total;
    }

    int Hand::Size() const
    {
        return cards_.size();
    }

    bool Hand::Blackjack() const
    {
        if(cards_.size() == 2 && this->Value() == 21)
        {
            return true;
        }
        return false;
    }

    bool Hand::Busted() const
    {
        if(this->Value() > 21)
        {
            return true;
        }
        return false;
    }

    bool Hand::Splittable()
    {
        if(cards_.size() == 2 && cards_[0]->rank() == cards_[1]->rank())
        {
            return true;
        }
        else
        {
            splitDeclined_ = true;
            return false;
        }
    }

    bool Hand::SplitDeclined() const
    {
        return splitDeclined_;
    }

    void Hand::SetBet(Bet& ante)
    {
        ante_ = &ante;
    }

    Bet& Hand::GetBet() const
    {
        return *ante_;
    }
    
    BlackjackPlayer& Hand::GetPlayer() const
    {
        return player_;
    }

    Card::Ptr Hand::GetUpCard() const
    {
        return cards_[0];
    }
    vector<Card::Ptr>::const_iterator Hand::begin()
    {
        return cards_.begin();
    }
    
    vector<Card::Ptr>::const_iterator Hand::end()
    {
        return cards_.end();
    }
} /* Casino */
