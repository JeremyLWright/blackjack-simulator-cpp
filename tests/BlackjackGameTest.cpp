#include <gmock/gmock.h>
#include "Application/Card.hpp"
#include "Application/Table.hpp"
#include "Application/BlackjackGame.hpp"
#include "Application/Shoe.hpp"

using ::testing::Return;
using namespace Casino;

class MockShoe : public Casino::Shoe {
    public:
        MOCK_METHOD0(Draw, Casino::Card::Ptr(void));
        MOCK_METHOD0(Shuffle, void(void));
};



TEST(BlackjameGame, DealerBusts)
{
	Casino::Table* mainTable = new Casino::Table();
    Casino::BlackjackPlayer* Jeremy = new Casino::BlackjackPlayer(*mainTable);
	Jeremy->AddMoney(1000);
    mainTable->AddPlayer(Jeremy);
    auto shoe = MockShoe();


	auto rank = new Card::ValueRank(2);
	auto suite = new Card::Suite(Card::Suite::HEARTS);
	auto card1 = new Card(*rank, *suite);

	EXPECT_CALL(shoe, Draw())
		.WillOnce(Return(card1));

    Casino::BlackjackGame game(shoe, *mainTable);

    game.Cycle();
    
	ASSERT_TRUE(false);
}