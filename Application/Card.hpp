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
                    /**
                     * Compare this suite to the given rhs. Necessary to allow
                     * std::algorithm sort and shuffle
                     */
                    virtual bool operator==(const Suite& rhs) const;                
                    SuiteType _value;
            };

            /**
             * Create a card with the given rank and Suite
             */
            Card(int rank, Suite const & suite);
            virtual ~Card();

            /**
             * Return the rank of the card.
             */
            virtual int Rank() const ;

            /** Return the soft value of the card (just the rank except for
             * aces)
             */
            virtual int SoftValue() const;

            /** Return the hard value of the card (Just the rank except for
             * aces)
             */
            virtual int HardValue() const;

            /** Return true of the card offer's insurance i.e. is an Ace.
             */
            virtual bool OfferInsurance() const;
            virtual std::string ToString() const;

            /**
             * Comparison operator for sorting and shuffling
             */
            virtual bool operator==(const Card& rhs) const;
            virtual bool operator<(const Card& rhs) const;
        protected:
            Card();

        private:
            int const _rank;
            Suite const & _suite;
    };
    
    enum class FaceRank {
        JACK,
        QUEEN,
        KING
    };

    class FaceCard : public Card {
        public: 
            typedef FaceCard* Ptr;
            FaceCard(FaceRank rank, Suite const & suite);
            virtual ~FaceCard();
            /**
             *  Return the softvalue of the card i.e. 10
             */
            virtual int SoftValue() const;

            /**
             * Return the hard value of the card i.e. 10
             */
            virtual int HardValue() const;
            virtual std::string ToString() const;
        private:
            FaceRank const _rank;
            Suite const & _suite;
    };

    class AceCard : public Card {
        public: 
            typedef AceCard* Ptr;
            AceCard(Suite const & suite);
            virtual ~AceCard();
            /**
             * Return the soft value of the card i.e. 1
             */
            virtual int SoftValue() const;

            /**
             * Return the hard value of the card i.e. 11
             */
            virtual int HardValue() const;

            /**
             * Return true, since this is an Ace Card.
             */
            virtual bool OfferInsurance() const;
            virtual std::string ToString() const;
        private:
            Suite const & _suite;
    };
}
#endif /* end of include guard: _CARD */
