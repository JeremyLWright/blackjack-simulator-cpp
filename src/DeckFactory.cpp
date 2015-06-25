#include <string>
#include <array>
#include <memory>
#include <vector>
#include "Card.hpp"
#include "DeckFactory.hpp"

using namespace std;

namespace Casino {
    vector<Card::Ptr> DeckFactory::GetDeck()
    {
        vector<Card::Ptr> deck;
		vector<Card::Suite> suites{Card::Suite::SPADES,
            Card::Suite::CLUBS,
            Card::Suite::DIAMONDS,
            Card::Suite::HEARTS};
        
        vector<FaceRank> faces{
            FaceRank::JACK,
            FaceRank::QUEEN,
            FaceRank::KING};

        for(Card::Suite suite : suites)
        {
			auto temp_suite = new Card::Suite(suite);

			 //Add the Ace
			auto ace = new AceCard(*temp_suite);
            deck.push_back(ace);

            for(int rank = 2; rank <= 10; ++rank)
            {
                deck.push_back(new Card(rank, *temp_suite));
            }

            for(FaceRank face :faces)
            {
                deck.push_back(new FaceCard(face, *temp_suite));
            }
        }

        return deck;
    }
} /* Casino */
