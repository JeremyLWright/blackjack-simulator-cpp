#include "Bet.hpp"
#include <sstream>

namespace Casino {
    Bet::Bet():
#if __GNUC__
        amount_{0},
#else
		  amount_(0),
#endif
        outcome_("Default", make_pair(0,1))
    {
    }

    Bet::Bet(int Amount, Odds odds):
#if __GNUC__
		 amount_{Amount},
        outcome_{odds}
#else
		amount_(Amount),
        outcome_(odds)
#endif
    {
    }

    Bet::~Bet()
    {
    }

    int Bet::WinAmount() const
    {
        return amount_*outcome_;
    }

    int Bet::LoseAmount() const
    {
        return amount_;
    }

    string Bet::ToString() const
    {
        stringstream ss;
        ss << "Amount on " << outcome_.ToString() << endl;
        return ss.str(); 
    }
} /* Casino */


