/**
 * @brief Shoe class representing a set of decks from which to deal and shuffle
 *
 * @par
 * Copyright Jeremy Wright (c) 2012 
 * Creative Commons Attribution-ShareAlike 3.0 Unported License.
 */

#ifndef _SHOE
#define _SHOE
#include <stdexcept>
#include <string>
using namespace std;


namespace Casino {
    struct EndOfShoeException : public std::logic_error
    {
        EndOfShoeException():
            logic_error("Deck needs to be shuffled.")
        {
        }
    };

    class Shoe {
        public:
            typedef vector<Card::Ptr>::const_iterator itr_type;
            /** Initialize a show with a given number of decks */
            Shoe (int decks=1);
			virtual ~Shoe ();
            /** Draw the next card from the shoe. */
			virtual Card::Ptr Draw();

            /** Shuffle the shoe of cards. */
            virtual void Shuffle();
            virtual vector<Card*>::const_iterator begin();
            virtual vector<Card*>::const_iterator end();
        private:
            vector<Card::Ptr> _decks;
            vector<Card::Ptr>::const_iterator _deal;
    };
} /* Casino */
#endif /* end of include guard: _SHOE */

