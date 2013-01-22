#include <string>
#include <sstream>
#include <stdexcept>
#include <vector>
#include <memory> 
#include <iostream>
#include "Card.hpp"
using namespace std;

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
                ss << " of Clubs";
                break;
            case DIAMONDS:
                ss << " of Diamonds";
                break;
            case HEARTS:
                ss << " of Hearts";
                break;
            case SPADES:
                ss << " of Spades";
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
        return (this->_rank.Value() == rhs._rank.Value()) && (this->_suite == rhs._suite);
    }

    bool Card::operator<(const Card& rhs) const
    {
        return ((this->_rank.Value()) < rhs._rank.Value());
    }

    FaceCard::FaceCard(Rank const & rank, Suite const & suite):
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

    AceCard::AceCard(Suite const & suite):
        Card(*(new FaceRank(Card::Rank::ACE)), suite)
    {
    }

    AceCard::~AceCard()
    {
        delete &_rank;
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

