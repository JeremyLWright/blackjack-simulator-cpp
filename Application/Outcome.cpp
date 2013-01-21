#include "Outcome.hpp"
#include <sstream>
namespace game {
    Outcome::Outcome(string Name, pair<intmax_t, intmax_t> Odds):
#if __clang__
        name_(Name),
        odds_(Odds)
#else
        name_{Name},
        odds_{Odds}
#endif
    {
        
    }

    Outcome::~Outcome()
    {
    }

    bool Outcome::operator==(Outcome const & rhs) const
    {
        return (this->ToString() == rhs.ToString());  
    }

    bool Outcome::operator!=(Outcome const & rhs) const
    {
        return !this->operator==(rhs);
    }

    string Outcome::ToString() const
    {
        stringstream ss;
        ss << name_ << " (" << odds_.first << ":" << odds_.second << ")";
        return ss.str();
    }
    
    int operator*(intmax_t Amount, Outcome const & rhs) 
    {
        return (Amount * rhs.odds_.first)/rhs.odds_.second;
    }
    
    int operator*(Outcome const & lhs, intmax_t Amount)
    {
        return operator*(Amount, lhs);
    }

} /* game */
