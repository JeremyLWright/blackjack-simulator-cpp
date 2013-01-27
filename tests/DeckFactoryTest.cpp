#include <array>
#include <memory>
#include <iostream>
#include "Card.hpp"
#include "DeckFactory.hpp"
#include "DeckFactoryTest.hpp"

using namespace std;

TEST(DeckFactoryTest, Simple)
{
    auto deck = Casino::DeckFactory::GetDeck();
    for(auto card : deck)
    {
		cout << card->ToString() << endl;
    }
}
