#include "ShoeTest.hpp"
#include "Card.hpp"
#include <memory>
#include <iostream>
#include "Shoe.hpp"
using namespace std;

TEST(ShoeTest, Simple)
{
    Casino::Shoe s(4);
    s.Shuffle();
	
    for(auto card : s)
    {
        EXPECT_NO_THROW(card->ToString());
    }

}
