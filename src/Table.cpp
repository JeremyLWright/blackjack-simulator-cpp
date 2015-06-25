#include "Table.hpp"
#include <memory>

using namespace std;
namespace Casino {
    TableLimitException::TableLimitException(double currentBetAmount, double currentCosts, int tableLimit):
        logic_error("Current Bet Exceeds Table Limit"),
#if __GNUC__
		betAmount_{currentBetAmount},
        tableCost_{currentCosts},
        tableLimit_{tableLimit}
#else
        betAmount_(currentBetAmount),
        tableCost_(currentCosts),
        tableLimit_(tableLimit)
#endif
    {
    }

    char const * TableLimitException::what() const throw()
    {
        stringstream ss;
        ss << "Current Bet Exceeds Table Limit: " 
            << betAmount_ << "/"
            << tableCost_ << "/"
            << tableLimit_ << "." << endl;
        return ss.str().c_str();
    }

    Table::Table(int limit):
        limit_(limit)
    {
    }

    Table::~Table()
    {
    }

    void Table::NewGame()
    {
        bets_.clear();
    }

    void Table::PlaceBet(Bet* bet, Hand* hand)
    {
        if(IsValid(*bet))
        {
            bets_.push_back(bet);    
            hand->SetBet(*bet);
        }
        else
        {
            throw TableLimitException(bet->WinAmount(), Cost(), limit_);
        }
    }

    bool Table::IsValid(Bet& bet) const
    {
        return (Cost() + bet.WinAmount() < limit_);
    }

    double Table::Cost() const
    {
        auto total = 0.0;
        for(auto bet : bets_)
        {
            total += bet->WinAmount();
        }
        return total;
    }

    string Table::ToString() const
    {
        return "Table";
    }

} /* Game */
