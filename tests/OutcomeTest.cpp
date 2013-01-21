#include "Outcome.hpp"
#include <gtest/gtest.h>

using namespace std;
using namespace Casino;
TEST(Outcomes, WinAmounts)
{
    Outcome o("Normal", make_pair(3,2));
    EXPECT_EQ(150, (o * 100) );
}

TEST(Outcomes, Compare)
{
    Outcome o1("Insurance", make_pair(1,1));
    Outcome o2("Insurance", make_pair(1,1));
    EXPECT_EQ(o1, o2);
    
    Outcome o3("Even", make_pair(1,1));
    EXPECT_NE(o1,o3); 
}
