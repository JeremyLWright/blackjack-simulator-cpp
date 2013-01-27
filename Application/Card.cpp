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
		if(!IsValidSuite(value))
		{
			throw logic_error("Invalid Suite when trying to construct Card::Suite::Suite");
		}
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

    bool Card::Rank::operator<(const Rank& rhs) const
    {
        return (this->Value() < rhs.Value());
    }

    bool Card::Rank::operator==(const Rank& rhs) const
    {
        return (this->Value() == rhs.Value());
    }

    bool Card::Suite::operator==(const Suite& rhs) const
    {
        return (this->_value == rhs._value);
    }

    /** Rank Methods **/
    Card::FaceRank::FaceRank(Card::Rank::RankType value):
        value_(value)
    {
    }

    Card::FaceRank::~FaceRank()
    {

    }

    Card::ValueRank::ValueRank(int value):
        value_(value)
    {
    }

    Card::ValueRank::~ValueRank()
    {
    }

    string Card::FaceRank::ToString() const
    {
        stringstream ss;
        switch(value_)
        {
            case JACK:
                ss << "J";
                break;
            case QUEEN:
                ss << "Q";
                break;
            case KING:
                ss << "K";
                break;
            case ACE:
                ss << "A";
                break;
        }
        return ss.str();
    }

    string Card::ValueRank::ToString() const
    {
        stringstream ss;
        ss << value_;
        return ss.str();
    }


    int Card::FaceRank::Value() const
    {
        return 10;
    }

    int Card::ValueRank::Value() const
    {
        return value_;
    }

    /** Card Methods **/
    Card::Card(Rank const & rank, Suite const & suite):
        _rank(rank),
        _suite(suite)
    {
		if(!IsValidSuite(suite))
		{
			stringstream ss;
			ss << "Invalid Suite when trying to construct Card::Card(rank=" << rank.ToString() << ",suite=???);";
			throw logic_error(ss.str());
		}
    }

    Card::~Card()
    {
    }

    string Card::ToString() const
    {
        stringstream ss;
        ss << _rank.ToString() << " of " << _suite.ToString();
        return ss.str();
    }

    int Card::rank() const
    {
        return _rank.Value();
    }

    int Card::SoftValue() const
    {
        return this->HardValue();
    }

    int Card::HardValue() const
    {
        return _rank.Value();
    }

    bool Card::OfferInsurance() const
    {
        return false;
    }

    bool Card::operator==(const Card& rhs) const
    {
        cerr << "comparing " << rhs._rank.Value() << " to " << _rank.Value() << endl;
        return (this->_rank.Value() == rhs._rank.Value()) && (this->_suite == rhs._suite);
    }

    bool Card::operator<(const Card& rhs) const
    {
        cerr << "comparing " << rhs._rank.Value() << " to " << _rank.Value() << endl;
        return ((this->_rank.Value()) < rhs._rank.Value());
    }

    FaceCard::FaceCard(Rank const & rank, Suite const & suite):
        Card(rank, suite)
    {
		if(!IsValidSuite(suite))
		{
			stringstream ss;
			ss << "Invalid Suite when trying to construct Card::FaceCard(rank=" << rank.ToString() << ",suite=???);";
			throw logic_error(ss.str());
		}
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

    AceCard::AceCard(Suite const & suite):
        Card(*(new FaceRank(Card::Rank::ACE)), suite)
    {
		if(!IsValidSuite(suite))
		{
			stringstream ss;
			ss << "Invalid Suite when trying to construct Card::AceCard(rank=ACE,suite=???);";
			throw logic_error(ss.str());
		}
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

