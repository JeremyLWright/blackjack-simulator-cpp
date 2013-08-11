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
            typedef Card* Ptr;
            struct Suite { 
                    enum SuiteType {
                        CLUBS,
                        DIAMONDS,
                        HEARTS,
                        SPADES
                    };

                    Suite(SuiteType value);
                    string ToString() const;
                    virtual bool operator==(const Suite& rhs) const;                
                    SuiteType _value;
            };

            Card(int rank, Suite const & suite);
            virtual ~Card();
            virtual int Rank() const ;
            virtual int SoftValue() const;
            virtual int HardValue() const;
            virtual bool OfferInsurance() const;
            virtual std::string ToString() const;
            virtual bool operator==(const Card& rhs) const;
            virtual bool operator<(const Card& rhs) const;
        protected:
            Card():
        _rank(0),
        _suite(Suite(Suite::CLUBS))
        {}

        private:
            int const _rank;
            Suite const & _suite;
    };
    
    enum class FaceRank {
        JACK,
        QUEEN,
        KING,
        ACE
    };

    class FaceCard : public Card {
        public: 
            typedef FaceCard* Ptr;
            FaceCard(FaceRank rank, Suite const & suite);
            virtual ~FaceCard();
            virtual int SoftValue() const;
            virtual int HardValue() const;
        private:
            FaceRank const _rank;
            Suite const & _suite;
    };

    class AceCard : public Card {
        public: 
            typedef AceCard* Ptr;
            AceCard(Suite const & suite);
            virtual ~AceCard();
            virtual int SoftValue() const;
            virtual int HardValue() const;
            virtual bool OfferInsurance() const;
        private:
            Suite const & _suite;
    };
}
#endif /* end of include guard: _CARD */
