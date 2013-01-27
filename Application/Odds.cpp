#include "Odds.hpp"
#include <sstream>
namespace Casino {
    Odds::Odds(string Name, pair<int, int> Odds):
#if __GNUC__
        name_{Name},
        odds_{Odds}
#else
        name_(Name),
        odds_(Odds)
#endif
    {
        
    }

    Odds::~Odds()
    {
    }

    bool Odds::operator==(Odds const & rhs) const
    {
        return (this->ToString() == rhs.ToString());  
    }

    bool Odds::operator!=(Odds const & rhs) const
    {
        return !this->operator==(rhs);
    }

    string Odds::ToString() const
    {
        stringstream ss;
        ss << name_ << " (" << odds_.first << ":" << odds_.second << ")";
        return ss.str();
    }
    
    int operator*(int Amount, Odds const & rhs) 
    {
        return (Amount * rhs.odds_.first)/rhs.odds_.second;
    }
    
    int operator*(Odds const & lhs, int Amount)
    {
        return operator*(Amount, lhs);
    }

} /* Casino */
