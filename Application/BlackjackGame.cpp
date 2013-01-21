#include "BlackjackGame.hpp"
#include "Card.hpp"
namespace Casino {
    BlackjackGame::BlackjackGame (Shoe shoe, Table table):
        shoe_(shoe),
        table_(table),
        dealer_(table)
    {
        dealItr_ = begin(shoe);
    }

    BlackjackGame::~BlackjackGame ()
    {
    }

    void BlackjackGame::InitPlayer(BlackjackPlayer& player)
    {
        player.NewGame();

        //Load the hand with 2 cards
        auto hand = player.GetFirstHand();
        hand->Add(*dealItr_); 
        ++dealItr_;
        hand->Add(*dealItr_);
        ++dealItr_;
    }

    void BlackjackGame::Cycle()
    {
        shoe_.Shuffle();
        for(auto player : players_)
        {
            InitPlayer(player);
        }

        InitPlayer(dealer_);
        auto dealersHand = dealer_.GetFirstHand();
        if(dealersHand->GetUpCard()->OfferInsurance())
            Insurance();
        
        //Initial deal, and splitting...
        for(auto player : players_)
        {
            for(auto playersHand : player)
            {
                if(playersHand->Splittable() && !playersHand->SplitDeclined())
                {
                    auto splitHand = player.Split(*playersHand.get());
                    splitHand->Add(*dealItr_);
                    dealItr_++;      
                    playersHand->Add(*dealItr_);
                    dealItr_++;      
                }
            }
        }

        //Fill hands, and betting...
        for(auto player : players_)
        {
            for(auto playersHand : player)
            {
                FillHand(*playersHand.get());
            }
        }

        FillHand(*dealersHand.get());

        if(dealersHand->Busted())
        {
            //Resolve all bets as winners
            for(auto player : players_)
            {
                for(auto playersHand : player)
                {
                    player.Win(*playersHand->GetBet().get());
                }
            }
        }

        for(auto player: players_)
        {
            for(auto playersHand : player)
            {
                if(playersHand->Value() > dealersHand->Value())
                {
                    player.Win(*playersHand->GetBet().get());
                }
            }
        }

        
        
    }

    void BlackjackGame::Insurance()
    {
        for(auto player : players_)
        {
            for(auto playersHand : player)
            {
                if(playersHand->Blackjack())
                {
                }
                else if(player.Insurance(*playersHand.get()))
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
                hand.Add(*dealItr_);
                dealItr_++;
                break;
            }
            else if(hand.GetPlayer().Hit(hand))
            {
                hand.Add(*dealItr_);
                dealItr_++;
            }
            else
            {
                break;
            }
        }
        if(hand.Busted())
        {
            hand.GetPlayer().Lose(*hand.GetBet().get());
        }
    }

    void BlackjackGame::AddPlayer(BlackjackPlayer&& player)
    {
        //players_.push_back(player);
    }

    string BlackjackGame::ToString()
    {
        return "It's a Casino...";
    }

} /* Casino */
