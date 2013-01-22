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
#include <memory>
using namespace std;

namespace Casino {

    class Card {
        public:
            typedef shared_ptr<Card> Ptr;
            class Suite { 
                public:
                    enum SuiteType {
                        CLUBS,
                        DIAMONDS,
                        HEARTS,
                        SPADES
                    };

                    Suite(SuiteType value);
                    string ToString() const;
                    virtual bool operator==(const Suite& rhs) const;
                private:
                    SuiteType _value;
            };

            class Rank { 
                public:
                    enum RankType {
                        JACK,
                        QUEEN,
                        KING,
                        ACE,
                    };
                    virtual ~Rank(){}
                    virtual string ToString() const = 0;
                    virtual int Value() const = 0;
            };

            class FaceRank : public Rank {
                public:
                    FaceRank(Card::Rank::RankType value);
                    virtual ~FaceRank();
                    virtual string ToString() const;
                    virtual int Value() const;
                private:
                    RankType value_;
            };

            class ValueRank : public Rank {
                public:
                    ValueRank(int value);
                    virtual ~ValueRank();
                    virtual string ToString() const;
                    virtual int Value() const;
                private:
                    int value_;
            };


            Card(Rank const & rank, Suite const & suite);
            virtual ~Card();
            virtual int rank() const ;
            virtual int SoftValue() const;
            virtual int HardValue() const;
            virtual bool OfferInsurance() const;
            virtual std::string ToString() const;
            virtual bool operator==(const Card& rhs) const;
            virtual bool operator<(const Card& rhs) const;
        protected:
            Rank const & _rank;
            Suite const & _suite;
    };

    class FaceCard : public Card {
        public: 
            typedef shared_ptr<FaceCard> Ptr;
            FaceCard(Rank const & rank, Suite const & suite);
            virtual ~FaceCard();
            virtual int SoftValue() const;
            virtual int HardValue() const;
    };

    class AceCard : public Card {
        public: 
            typedef shared_ptr<AceCard> Ptr;
            AceCard(Suite const & suite);
            virtual ~AceCard();
            virtual int SoftValue() const;
            virtual int HardValue() const;
            virtual bool OfferInsurance() const;
    };
}
#endif /* end of include guard: _CARD */
