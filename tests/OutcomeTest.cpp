#include "Odds.hpp"
#include <gtest/gtest.h>

using namespace std;
using namespace Casino;
TEST(Oddss, WinAmounts)
{
    Odds o("Normal", make_pair(3,2));
    EXPECT_EQ(150, (o * 100) );
}

TEST(Oddss, Compare)
{
    Odds o1("Insurance", make_pair(1,1));
    Odds o2("Insurance", make_pair(1,1));
    EXPECT_EQ(o1, o2);
    
    Odds o3("Even", make_pair(1,1));
    EXPECT_NE(o1,o3); 
}
