

#include "gtest/gtest.h"
#include "../../event/header/event.h" 
using namespace std;

string getMenuOutput() {
    ostringstream oss;
    oss << "\nMain Menu:\n"
        "1. User Authentication\n"
        "2. Project Setup\n"
        "3. Task Assignment\n"
        "4. Progress Tracking\n"
        "5. Reporting\n"
        "6. Exit\n";
    return oss.str();
}

TEST(MainMenuTest, OutputCheck) {
    string expectedOutput = getMenuOutput();
    ostringstream realOutput;
    streambuf* oldCoutBuffer = cout.rdbuf(realOutput.rdbuf());
    mainMenu();
    cout.rdbuf(oldCoutBuffer);

    EXPECT_EQ(realOutput.str(), expectedOutput);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}



