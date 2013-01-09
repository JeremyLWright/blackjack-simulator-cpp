#include <string>
#include <array>
#include <memory>
#include <vector>
#include "Card.hpp"
#include "DeckFactory.hpp"

using namespace std;

namespace Casino {
    vector<Card*> DeckFactory::GetDeck()
    {
        vector<Card*> deck;
        vector<Card::Suite> suites{Card::Suite::SPADES,
            Card::Suite::CLUBS,
            Card::Suite::DIAMONDS,
            Card::Suite::HEARTS};
        
        vector<Card::Rank::RankType> faces{Card::Rank::JACK,
            Card::Rank::QUEEN,
            Card::Rank::KING,
            Card::Rank::ACE};

        for(Card::Suite suite : suites)
        {
            for(int rank = 2; rank <= 10; ++rank)
            {
                auto temp_rank = new Card::ValueRank(rank);
                deck.push_back(new Card(*temp_rank, suite));
            }

            //Add the Ace
            deck.push_back( new AceCard(suite));

            for(Card::Rank::RankType face :faces)
            {
                auto temp_face = new Card::FaceRank(face);
                deck.push_back(new FaceCard(*(temp_face), suite));
            }
        }

        return deck;
    }
} /* Casino */
