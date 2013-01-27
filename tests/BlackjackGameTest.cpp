#include <gmock/gmock.h>
#include "Application/Card.hpp"
#include "Application/Table.hpp"
#include "Application/BlackjackGame.hpp"
#include "Application/Shoe.hpp"

using ::testing::Return;
using ::testing::_;
using namespace Casino;

class MockShoe : public Casino::Shoe {
    public:
        MOCK_METHOD0(Draw, Card::Ptr(void));
        MOCK_METHOD0(Shuffle, void(void));
};

class MockPlayer : public Casino::BlackjackPlayer {
	public:
#if 0
		MOCK_METHOD0(NewGame, void(void));
		MOCK_CONST_METHOD0(GetFirstHand, Hand::Ptr(void));
		MOCK_CONST_METHOD0(IsPlaying, bool(void));
		MOCK_METHOD0(PlaceBets, void(void));
#endif
        MOCK_METHOD1(Win, void(Bet const &));
        MOCK_METHOD1(Lose, void(Bet const &));
#if 0
        MOCK_CONST_METHOD1(EvenMoney, bool(Hand& hand));
        MOCK_CONST_METHOD1(Insurance, bool(Hand& hand));
        MOCK_METHOD1(Split, Hand::Ptr(Hand& hand));
        MOCK_CONST_METHOD1(DoubleDown, bool(Hand&));
        MOCK_CONST_METHOD1(Hit, bool(Hand&));
		MOCK_METHOD1(AddMoney, void(int));

        MOCK_METHOD0(begin, vector<Hand::Ptr>::iterator(void));
        MOCK_METHOD0(end, vector<Hand::Ptr>::iterator(void));
#endif
};


TEST(BlackjameGame, DealerBusts)
{
	Casino::Table::Ptr mainTable = new Casino::Table();
    MockPlayer* FakeJeremy = new MockPlayer();
	FakeJeremy->AddMoney(1000);
    MockShoe shoe;

	auto heart = new Card::Suite(Card::Suite::HEARTS);
	auto club = new Card::Suite(Card::Suite::CLUBS);

	auto rank10 = new Card::ValueRank(10);
	auto card10 = new Card(*rank10, *heart);

	auto rank7 = new Card::ValueRank(7);
	auto card7 = new Card(*rank7, *club);

	auto rank2 = new Card::ValueRank(2);
	auto card2 = new Card(*rank2, *club);


	// This game I expect the following things to happen

	EXPECT_CALL(shoe, Shuffle());

	EXPECT_CALL(shoe, Draw())
		.WillOnce(Return(card7))	//Player.Value() == 7
		.WillOnce(Return(card10))	//Player.Value() == 17
		.WillOnce(Return(card2))	//Dealer.Value() == 2
		.WillOnce(Return(card10))	//Dealer.Value() == 12
		.WillOnce(Return(card10));	//Dealer.Value() == 22 -> Busted
	
	// Since the dealer busted, Jeremy should win...
	EXPECT_CALL(*FakeJeremy, Win(_)); //The _ means I don't care what the input is.
	
	//Do it...
    Casino::BlackjackGame game(shoe, mainTable);
	game.AddPlayer(FakeJeremy);

    game.Cycle();
    
	
	delete heart;
	delete club;

	delete rank10;
	delete card10;
	
	delete rank2;
	delete card2;
	
	delete rank7;
	delete card7;

	delete mainTable;
	delete FakeJeremy;
	
}