#include "BlackjackGame.hpp"
#include "Card.hpp"
#include <iostream>
using namespace std;
namespace Casino {
    BlackjackGame::BlackjackGame (Shoe& shoe, Table& table):
        shoe_(shoe),
        table_(table),
        dealer_(table)
    {
		dealer_.AddMoney(1000000);
    }

    BlackjackGame::~BlackjackGame ()
    {
    }

    void BlackjackGame::InitPlayer(BlackjackPlayer& player)
    {
        player.NewGame();

        //Load the hand with 2 cards
        auto hand = player.GetFirstHand();
		hand->Add(shoe_.Draw()); 
        hand->Add(shoe_.Draw());        
		player.PlaceBets();
    }

    void BlackjackGame::Cycle()
    {
        shoe_.Shuffle();
		cout << "Loading Player's Hands" << endl;
        for(auto player : players_)
        {
            InitPlayer(*player);
        }

        InitPlayer(dealer_);
        auto dealersHand = dealer_.GetFirstHand();
        if(dealersHand->GetUpCard()->OfferInsurance())
            Insurance();
        
        //Initial deal, and splitting...
        for(auto player : players_)
        {
            for(auto playersHand : *player)
            {
                if(playersHand->Splittable() && !playersHand->SplitDeclined())
                {
                    auto splitHand = player->Split(*playersHand);
                    splitHand->Add(shoe_.Draw());
                    playersHand->Add(shoe_.Draw());
                }
            }
        }

        //Fill hands, and betting...
        for(auto player : players_)
        {
            for(auto playersHand : *player)
            {
                FillHand(*playersHand);
            }
        }

        FillHand(*dealersHand);

        if(dealersHand->Busted())
        {
			cout << "Dealer Busted - Everyone Wins." << endl;
            //Resolve all bets as winners
            for(auto player : players_)
            {
                for(auto playersHand : *player)
                {
                    player->Win(playersHand->GetBet());
                }
            }
        }

        for(auto player: players_)
        {
            for(auto playersHand : *player)
            {
				auto dealerScore = dealersHand->Value();
				auto playerScore = playersHand->Value();
				cout << "Dealer Got " << dealerScore << " you got " << playerScore << "." << endl;
                if(playerScore > dealerScore)
                {
                    player->Win(playersHand->GetBet());
                }
				else
				{
					player->Lose(playersHand->GetBet());
				}
            }
        }

        
        
    }

    void BlackjackGame::Insurance()
    {
        for(auto player : players_)
        {
            for(auto playersHand : *player)
            {
                if(playersHand->Blackjack())
                {
                }
                else if(player->Insurance(*playersHand))
                {
                }

            }
        }
    }

    void BlackjackGame::FillHand(Hand& hand)
    {
        while(!hand.Busted())
        {
            if(hand.GetPlayer().DoubleDown(hand))
            {
                hand.Add(shoe_.Draw());
                break;
            }
            else if(hand.GetPlayer().Hit(hand))
            {
                hand.Add(shoe_.Draw());
            }
            else
            {
                break;
            }
        }
        if(hand.Busted())
        {
            hand.GetPlayer().Lose(hand.GetBet());
        }
    }

    void BlackjackGame::AddPlayer(BlackjackPlayer* player)
    {
        players_.push_back(player);
    }

    string BlackjackGame::ToString()
    {
        return "It's a Casino...";
    }

} /* Casino */
