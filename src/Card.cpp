#include <string>
#include <sstream>
#include <stdexcept>
#include <vector>
#include <memory> 
#include <iostream>
#include <algorithm>
#include "Card.hpp"
using namespace std;

namespace {
	bool IsValidSuite(Casino::Card::Suite::SuiteType const & value)
	{
		vector<Casino::Card::Suite::SuiteType> valid_suites;
            valid_suites.push_back(Casino::Card::Suite::SPADES);
            valid_suites.push_back(Casino::Card::Suite::CLUBS);
            valid_suites.push_back(Casino::Card::Suite::DIAMONDS);
            valid_suites.push_back(Casino::Card::Suite::HEARTS);

			if(none_of(begin(valid_suites), end(valid_suites), [&value](Casino::Card::Suite::SuiteType s){ return value != s;}))
				return false;

			return true;
	}

	bool IsValidSuite(Casino::Card::Suite const & suite)
	{
		return IsValidSuite(suite._value);
	}
}


namespace Casino {

    /** Suite Methods **/
    Card::Suite::Suite(SuiteType value):
        _value(value)
    {
	}

    string Card::Suite::ToString() const
    {
        stringstream ss;
        switch(_value)
        {
            case CLUBS:
                ss << "Clubs";
                break;
            case DIAMONDS:
                ss << "Diamonds";
                break;
            case HEARTS:
                ss << "Hearts";
                break;
            case SPADES:
                ss << "Spades";
                break;
            default:
                throw logic_error("Invalid Card::Suite");
                break;
        }
        return ss.str();
    }

    bool Card::Suite::operator==(const Suite& rhs) const
    {
        return (this->_value == rhs._value);
    }


    /** Card Methods **/
    Card::Card():
        _rank(0),
        _suite(Suite(Suite::CLUBS))
    {
    }

    Card::Card(int rank, Suite const & suite):
        _rank(rank),
        _suite(suite)
    {
    }

    Card::~Card()
    {
    }

    string Card::ToString() const
    {
        stringstream ss;
        ss << _rank << " of " << _suite.ToString();
        return ss.str();
    }

    int Card::Rank() const
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

    FaceCard::FaceCard(FaceRank rank, Suite const & suite):
        _rank(rank),
        _suite(suite)
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
    string FaceCard::ToString() const
    {
        stringstream ss;
        switch(_rank)
        {
            case FaceRank::JACK:
                ss << "Jack";
                break;
            case FaceRank::QUEEN:
                ss << "Queen";
                break;
            case FaceRank::KING:
                ss << "King";
                break;
            default:
                throw logic_error("Invalid Suite.");
        }
        ss << " of " << _suite.ToString();
        return ss.str();
    }

    AceCard::AceCard(Suite const & suite):
        _suite(suite)
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
    string AceCard::ToString() const
    {
        stringstream ss;
        ss << "Ace of " << _suite.ToString();
        return ss.str();
    }

}

