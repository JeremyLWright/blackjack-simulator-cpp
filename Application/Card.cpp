#include <string>
#include <sstream>
#include <stdexcept>
#include <vector>
#include <memory> 
#include <iostream>
#include "Card.hpp"
using namespace std;

namespace game {

    Card::Card(int rank, Suite suite):
        _rank(rank),
        _suite(suite)
    {
    }
 
    Card::~Card()
    {
    }
  
    string Card::ToString()
    {
        stringstream ss;
        ss << _rank->ToString() << " of " << _suit->ToString();
        return ss.str();
    }
    
    int Card::rank()
    {
        return _rank;
    }

    int Card::SoftValue() const
    {
        return this->HardValue();
    }

    int Card::HardValue() const
    {
        return _rank;
    }

    bool Card::OfferInsurance() const
    {
        return false;
    }
        
    bool Card::operator==(const Card& rhs) const
    {
        return (this->_rank == rhs._rank) && (this->_suite == rhs._suite);
    }

    bool Card::operator<(const Card& rhs) const
    {
        return ((this->_rank) < rhs._rank);
    }

    FaceCard::FaceCard(int rank, Suite suite):
        Card(rank, suite)
    {
    }

    FaceCard::~FaceCard()
    {
    }


    int FaceCard::SoftValue() const
    {
        return this->HardValue();
    }

    int FaceCard::HardValue() const
    {
        return 10;
    }

    AceCard::AceCard(Suite suite):
        Card(this->HardValue(), suite)
    {
    }

    AceCard::~AceCard()
    {
    }

    int AceCard::SoftValue() const
    {
        return 1;
    }

    int AceCard::HardValue() const
    {
        return 11;
    }
    
    bool AceCard::OfferInsurance() const
    {
        return true;
    }

}
   
