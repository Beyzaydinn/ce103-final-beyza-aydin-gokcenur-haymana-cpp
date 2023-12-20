//#define ENABLE_EVENT_TEST  // Uncomment this line to enable the Event tests

#include "gtest/gtest.h"
#include "../../event/header/event.h"  // Adjust this include path based on your project structure

using namespace Coruh::Event;

class EventTest : public ::testing::Test {
protected:
	void SetUp() override {
		// Setup test data
	}

	void TearDown() override {
		// Clean up test data
	}
};

TEST_F(EventTest, TestAdd) {
	double result = Event::add(5.0, 3.0);
	EXPECT_DOUBLE_EQ(result, 8.0);
}

TEST_F(EventTest, TestSubtract) {
	double result = Event::subtract(5.0, 3.0);
	EXPECT_DOUBLE_EQ(result, 2.0);
}

TEST_F(EventTest, TestMultiply) {
	double result = Event::multiply(5.0, 3.0);
	EXPECT_DOUBLE_EQ(result, 15.0);
}

TEST_F(EventTest, TestDivide) {
	double result = Event::divide(6.0, 3.0);
	EXPECT_DOUBLE_EQ(result, 2.0);
}

TEST_F(EventTest, TestDivideByZero) {
	EXPECT_THROW(Event::divide(5.0, 0.0), std::invalid_argument);
}

/**
 * @brief The main function of the test program.
 *
 * @param argc The number of command-line arguments.
 * @param argv An array of command-line argument strings.
 * @return int The exit status of the program.
 */
int main(int argc, char** argv) {
#ifdef ENABLE_EVENT_TEST
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
#else
	return 0;
#endif
}