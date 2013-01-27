/**
 * @brief Shoe class representing a set of decks from which to deal and shuffle
 *
 * @par
 * Copyright Jeremy Wright (c) 2012 
 * Creative Commons Attribution-ShareAlike 3.0 Unported License.
 */

#ifndef _SHOE
#define _SHOE

using namespace std;

namespace Casino {

    class Shoe {
        public:
            typedef vector<Card::Ptr>::const_iterator itr_type;
            Shoe (int decks=1);
			virtual ~Shoe ();
			virtual Card::Ptr Draw();
            virtual void Shuffle();
#if 1
            virtual vector<Card*>::const_iterator begin();
            virtual vector<Card*>::const_iterator end();
#endif
        private:
            vector<Card::Ptr> _decks;
            vector<Card::Ptr>::const_iterator _deal;
    };
#if 0
    template <class C> auto begin(Shoe& s) -> decltype(s.begin());
    template <class C> auto end(Shoe& s) -> decltype(s.end());
#endif
} /* Casino */
#endif /* end of include guard: _SHOE */

