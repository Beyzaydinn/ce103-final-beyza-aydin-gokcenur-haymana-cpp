#include <gtest/gtest.h>
#include "../../event/header/event.h"
#include "../../event/src/event.cpp"

class AuthenticateLoginTest : public ::testing::Test {
protected:
    void SetUp() override {
    }
    void TearDown() override {
    }
};
TEST_F(AuthenticateLoginTest, CorrectPassword) {
    login user;
    user.password = "correct_password";
    string enteredPassword = "correct_password";

    bool result = authenticateLogin(user, enteredPassword);

    ASSERT_TRUE(result) << "Authentication should be successful for correct password";
}

TEST_F(AuthenticateLoginTest, IncorrectPassword) {
    login user;
    user.password = "correct_password";
    string enteredPassword = "incorrect_password";

    bool result = authenticateLogin(user, enteredPassword);

    ASSERT_FALSE(result) << "Authentication should fail for incorrect password";
}

class WriteUserInfoToFileTest : public ::testing::Test {
protected:
    void SetUp() override {
    }
    void TearDown() override {
    }
};

TEST_F(WriteUserInfoToFileTest, SuccessfulWrite) {
    login user;
    const char* organization = "event_organization.bin";
    bool result = writeUserInfoToFile(user, organization);
    ASSERT_TRUE(result) << "Write to file should be successful";
}

class UserRecordTest : public ::testing::Test {
protected:
    void SetUp() override {
    }
    void TearDown() override {
    }
};
TEST_F(UserRecordTest, SuccessfulWrite) {
    recording store;
    const char* organization = "event_organization.bin";
    bool result = userRecord(store, organization);
    ASSERT_TRUE(result) << "Write to file should be successful";
}
class UserChoiceTest : public ::testing::Test {
protected:
    void SetUp() override {
    }
    void TearDown() override {
    }
}; 
TEST_F(UserChoiceTest, SuccessfulWrite) {
    choose create;
    const char* organization = "event_organization.bin";
    bool result = userChoice(create, organization);
    ASSERT_TRUE(result) << "Write to file should be successful";
}
class attendeesLoginTest : public ::testing::Test {
protected:
    void SetUp() override {
    }
    void TearDown() override {
    }
};
TEST_F(attendeesLoginTest, SuccessfulWrite) {
    login user;
    const char* organization = "event_organization.bin";
    bool result = attendeesLogin(user, organization);
    ASSERT_TRUE(result) << "Write to file should be successful";
}

class MainMenuTest : public ::testing::Test {
protected:
    void SetUp() override {
    }
    void TearDown() override {
    }
};

TEST(MainMenuTest, DisplayMenu) {
    testing::internal::CaptureStdout();  
    mainMenu();
    string output = testing::internal::GetCapturedStdout();
    string expected_output = "\nMain Menu:\n1. User Authentication\n2. Project Setup\n3. Task Assignment\n4. Progress Tracking\n5. Reporting\n6. Exit\n";
    ASSERT_EQ(output, expected_output);
}

class userAuthenticationTest : public ::testing::Test {
protected:
    void SetUp() override {
    }
    void TearDown() override {
    }
};

TEST(userAuthenticationTest, DisplayMenu) {
    testing::internal::CaptureStdout();
    userAuthentication();
    string output = testing::internal::GetCapturedStdout();
    string expected_output = "\n1. Login \n2. Register \n3. Guest Mode \n"; 
    ASSERT_EQ(output, expected_output);   
}

class ProjectSetupTest : public ::testing::Test {
protected:
    void SetUp() override {
    }
    void TearDown() override {
    }
};

TEST(ProjectSetupTest, DisplayMenu) {
    testing::internal::CaptureStdout();
    projectSetup(); 
    string output = testing::internal::GetCapturedStdout();
    string expected_output = "\n1. Create Event:\n2. Manage Event:\n";
    ASSERT_EQ(output, expected_output);
}

class TypeTest : public ::testing::Test {
protected:
    void SetUp() override {
    }
    void TearDown() override {
    }
};

TEST(TypeTest, DisplayMenu) {
    testing::internal::CaptureStdout();
    type();
    string output = testing::internal::GetCapturedStdout();
    string expected_output = "\n1) Wedding\n2) Birthday\n3) Bride\n4) Circumcision\n5) Engagement\n6) Baby Shower\n";
    ASSERT_EQ(output, expected_output);
}

class MenuTest : public ::testing::Test {
protected:
    void SetUp() override {
    }
    void TearDown() override {
    }
};

TEST(MenuTest, DisplayMenu) {
    testing::internal::CaptureStdout();
    menu(); 
    string output = testing::internal::GetCapturedStdout();
    string expected_output = "\n1. Food Menu\n2. Cake Menu\n";
    ASSERT_EQ(output, expected_output);
}

class ColorTest : public ::testing::Test {
protected:
    void SetUp() override {
    }
    void TearDown() override {
    }
};
 
TEST( ColorTest, DisplayMenu) {  
    testing::internal::CaptureStdout();
    color();
    string output = testing::internal::GetCapturedStdout();
    string expected_output = "\n1. Pink and Blue\n2. Red and Black\n3. Cream color and Brown\n4. White and Black\n";
    ASSERT_EQ(output, expected_output);
}


class VenueTest : public ::testing::Test {
protected:
    void SetUp() override {
    }
    void TearDown() override {
    }
};

TEST( VenueTest, DisplayMenu) {
    testing::internal::CaptureStdout();
    venue();
    string output = testing::internal::GetCapturedStdout();
    string expected_output = "\n1. Indoor event hall\n2. Beach Side\n3. Countryside Organization\n";
    ASSERT_EQ(output, expected_output);
}

class UserPlanTest : public ::testing::Test {
protected:
    void SetUp() override {
    }
    void TearDown() override {
    }
};

TEST(UserPlanTest, DisplayMenu) {
    testing::internal::CaptureStdout();
    userPlan();
    string output = testing::internal::GetCapturedStdout();
    string expected_output = "\nYour type: \nYour venue: \nYour color type: \nYour menu: \n";
    ASSERT_EQ(output, expected_output);
}

class TaskAssignmentTest : public ::testing::Test {
protected:
    void SetUp() override {
    }
    void TearDown() override {
    }
};

TEST(TaskAssignmentTest, DisplayMenu) {
    testing::internal::CaptureStdout();
    taskAssignment(); 
    string output = testing::internal::GetCapturedStdout();
    string expected_output = "\n1. Register Attendees: \n2. Track Attendees: \n";
    ASSERT_EQ(output, expected_output);
}


int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
