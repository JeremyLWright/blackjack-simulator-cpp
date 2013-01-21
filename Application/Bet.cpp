#include "Bet.hpp"
#include <sstream>

namespace game {
    Bet::Bet():
        amount_{0},
        outcome_("Default", make_pair(0,1))
    {
    }
    Bet::Bet(intmax_t Amount, Outcome odds):
#if __clang__
        amount_(Amount),
        outcome_(odds)
#else
        amount_{Amount},
        outcome_{odds}
#endif
    {
    }

    Bet::~Bet()
    {
    }
    intmax_t Bet::WinAmount() const
    {
        return amount_*outcome_;
    }

    intmax_t Bet::LoseAmount() const
    {
        return  amount_;
    }

    string Bet::ToString() const
    {
        stringstream ss;
        ss << "Amount on " << outcome_.ToString() << endl;
        return ss.str(); 
    }
} /* game */

