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
    Shoe::Shoe(int decks)
    {
        for(int i = 0; i < decks; ++i)
        {
            for(auto card : DeckFactory::GetDeck())
                _decks.push_back(card); 
        }
        _deal = std::begin(_decks);
    }

    Shoe::~Shoe()
    {
    }

    void Shoe::Shuffle()
    {
        random_device rd;
        minstd_rand0 randSource(rd());
        shuffle(std::begin(_decks), std::end(_decks), randSource);
		_deal = std::begin(_decks);
    }

	Card::Ptr Shoe::Draw()
	{
		auto c = *_deal;
		if(_deal == std::end(_decks))
			throw logic_error("End of the deck");
		++_deal;
		return c;
	}


    vector<Card*>::const_iterator Shoe::begin()
    {
        return std::begin(_decks);
    }

    vector<Card*>::const_iterator Shoe::end()
    {
        return std::end(_decks); 
    }

    
} /* Casino */
