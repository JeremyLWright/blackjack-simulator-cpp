#include <string>
#include <array>
#include <memory>
#include <vector>
#include "Card.hpp"
#include "DeckFactory.hpp"

using namespace std;

namespace Casino {
    array<shared_ptr<Card>,52> DeckFactory::GetDeck()
    {
        array<shared_ptr<Card>, 52> deck;
        auto deck_pos = begin(deck);
#if __clang__
        vector<Card::Suite> suites;
            suites.push_back(Card::Suite::SPADES);
            suites.push_back(Card::Suite::CLUBS);
            suites.push_back(Card::Suite::DIAMONDS);
            suites.push_back(Card::Suite::HEARTS);
#else   
        vector<Card::Suite> suites{Card::Suite::SPADES,
            Card::Suite::CLUBS,
            Card::Suite::DIAMONDS,
            Card::Suite::HEARTS};
        
        vector<Card::Rank::RankType> faces{Card::Rank::JACK,
            Card::Rank::QUEEN,
            Card::Rank::KING,
            Card::Rank::ACE};
#endif

        for(Card::Suite suite : suites)
        {
            for(int rank = 2; rank <= 10; ++rank)
            {
                auto temp_rank = new Card::ValueRank(rank);
                *deck_pos = make_shared<Card>(Card(*temp_rank, suite));
                ++deck_pos;
            }

            //Add the Ace
            *deck_pos = make_shared<AceCard>(AceCard(suite));
            ++deck_pos;

            for(Card::Rank::RankType face :faces)
            {
                auto temp_face = new Card::FaceRank(face);
                *deck_pos = make_shared<FaceCard>(FaceCard(*(temp_face), suite));
                ++deck_pos;
            }
        }

        return deck;
    }
} /* Casino */
