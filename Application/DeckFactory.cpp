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
#if __GNUC__
		        vector<Card::Suite> suites{Card::Suite::SPADES,
            Card::Suite::CLUBS,
            Card::Suite::DIAMONDS,
            Card::Suite::HEARTS};
        
        vector<FaceRank> faces{
            FaceRank::JACK,
            FaceRank::QUEEN,
            FaceRank::KING};
#else
		
        vector<Card::Suite::SuiteType> suites;
            suites.push_back(Card::Suite::SPADES);
            suites.push_back(Card::Suite::CLUBS);
            suites.push_back(Card::Suite::DIAMONDS);
            suites.push_back(Card::Suite::HEARTS);

		vector<Card::Rank::RankType> faces;
		faces.push_back(Card::Rank::JACK);
        faces.push_back(Card::Rank::QUEEN);
        faces.push_back(Card::Rank::KING);
#endif

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
