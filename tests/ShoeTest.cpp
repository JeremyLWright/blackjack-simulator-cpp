#include "ShoeTest.hpp"
#include "Card.hpp"
#include <memory>
#include <iostream>
#include "Shoe.hpp"

using namespace std;

TEST(ShoeTest, Simple)
{
    Casino::Shoe s(4, 1);
    s.Shuffle();
#if 0
    for(auto card : s)
    {
        cout << card->ToString() << endl;
    }
#endif
}
