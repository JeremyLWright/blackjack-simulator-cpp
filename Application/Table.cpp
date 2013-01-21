#include "Table.hpp"
#include <memory>

using namespace std;
namespace Game {
    TableLimitException::TableLimitException(int currentBetAmount, int currentCosts, int tableLimit):
        logic_error("Current Bet Exceeds Table Limit"),
        betAmount_{currentBetAmount},
        tableCost_{currentCosts},
        tableLimit_{tableLimit}
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
        limit_{limit}
    {
    }

    Table::~Table()
    {
    }

    void Table::AddPlayer(Player& player)
    {
        _players.push_back(&player);
    }

    void Table::PlaceBet(Bet& bet, Hand& hand)
    {
        if(IsValid(bet))
        {
            auto sharedBet = make_shared<Bet>(bet);
            bets_.push_back(sharedBet);    
            hand.SetBet(sharedBet);
        }
        else
        {
            throw TableLimitException(bet.WinAmount(), Cost(), limit_);
        }
    }

    bool Table::IsValid(Bet& bet) const
    {
        return (Cost() + bet.WinAmount() < limit_);
    }

    int Table::Cost() const
    {
        auto total = 0;
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
