/**
 * @brief Abstract Card Class
 *
 * @par
 * Copyright Jeremy Wright (c) 2012 
 * Creative Commons Attribution-ShareAlike 3.0 Unported License.
 */
#ifndef _CARD
#define _CARD

#include <string>
#include <utility>
namespace game {

    class Card {
        public:
        class Suite { 
            public:
                enum SuiteType {
                    CLUBS,
                    DIAMONDS,
                    HEARTS,
                    SPADES
                };

                Suite(SuiteType value):
                    _value(value)
                {
                }

                string ToString() const
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

            private:
                SuiteTypes _value;
        };
        class Rank { 
            public:
                enum RankType {
                    JACK,
                    QUEEN,
                    KING,
                    ACE,
                    NONE
                };

                Rank(RankType value):
                    _rankvalue(value)
            {
            }

                Rank(int value):
                    _rankvalue(NONE),
                    _intvalue(value)
            {
            }


                string ToString() const
                {
                    stringstream ss;
                    switch(_rankvalue)
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
                        case NONE: //Intentional fallthrough
                        default:
                            ss << _intvalue;
                            break;

                    }
                    return ss.str();
                }

            private:
                RankTypes _rankvalue;
                int _intvalue;
        };


        Card(int rank, Suite suite);
        virtual ~Card();
        virtual int rank();
        virtual int SoftValue() const;
        virtual int HardValue() const;
        virtual bool OfferInsurance() const;
        virtual std::string ToString();
        virtual bool operator==(const Card& rhs) const;
        virtual bool operator<(const Card& rhs) const;
        protected:
        Rank _rank;
        Suite _suite;
    };

    class FaceCard : public Card {
        public: 
            FaceCard(Rank rank, Suite suite);
            virtual ~FaceCard();
            virtual int SoftValue() const;
            virtual int HardValue() const;
    };

    class AceCard : public Card {
        public: 
            AceCard(Suite suite);
            virtual ~AceCard();
            virtual int SoftValue() const;
            virtual int HardValue() const;
            virtual bool OfferInsurance() const;
    };
}
#endif /* end of include guard: _CARD */
