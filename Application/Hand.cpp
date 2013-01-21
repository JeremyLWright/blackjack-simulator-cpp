#include <vector>
#include <memory>
#include <algorithm>
#include "Card.hpp"
#include "Hand.hpp"

namespace Casino {
    Hand::Hand(BlackjackPlayer& player):
        aceCount_{0},
        player_(player)
    {
    }

    Hand::~Hand()
    {
    }

    void Hand::Add(shared_ptr<Card> card)
    {
        cards_.push_back(card);
    }
    
    void Hand::Add(shared_ptr<AceCard> card)
    {
        cards_.push_back(card);
        aceCount_++;
    }

    int Hand::Value() const
    {
        int total{0};
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

    void Hand::SetBet(shared_ptr<Bet> ante)
    {
        ante_ = ante;
    }

    shared_ptr<Bet> Hand::GetBet() const
    {
        return ante_;
    }
    
    BlackjackPlayer& Hand::GetPlayer() const
    {
        return player_;
    }

    shared_ptr<Card> Hand::GetUpCard() const
    {
        return cards_[0];
    }
    vector<shared_ptr<Card>>::const_iterator Hand::begin()
    {
        return cards_.begin();
    }
    
    vector<shared_ptr<Card>>::const_iterator Hand::end()
    {
        return cards_.end();
    }
} /* Casino */
