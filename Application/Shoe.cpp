#include <vector>
#include <array>
#include <memory>
#include <random>
#include <algorithm>
#include "Card.hpp"
#include "Shoe.hpp"
#include "DeckFactory.hpp"

using namespace std;

namespace Casino {
    Shoe::Shoe(int decks, int stopDeal )
    {
        for(int i = 0; i < decks; ++i)
        {
            for(auto card : DeckFactory::GetDeck())
                _decks.push_back(card); 
        }
        _deal = std::begin(_decks);
        _stopDeal = std::end(_decks)-(52*stopDeal); 
    }

    Shoe::~Shoe()
    {
    }

    void Shoe::Shuffle()
    {
        random_device rd;
        minstd_rand0 randSource(rd());
        shuffle(std::begin(_decks), std::end(_decks), randSource);
    }

    vector<shared_ptr<Card>>::const_iterator Shoe::begin()
    {
        return _deal;
    }

    vector<shared_ptr<Card>>::const_iterator Shoe::end()
    {
        return _stopDeal; 
    }

    
} /* Casino */
