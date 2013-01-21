/**
 * @brief Create a valid 52-card deck and returns it as an array
 *
 * @par
 * Copyright Jeremy Wright (c) 2012 
 * Creative Commons Attribution-ShareAlike 3.0 Unported License.
 */

#ifndef _DECKFACTORY
#define _DECKFACTORY

namespace game {

    class DeckFactory {
        public:
        static std::array<std::shared_ptr<Card>, 52> GetDeck();
    };

} /* game */

#endif /* end of include guard: _DECKFACTORY */
