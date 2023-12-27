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

TEST(AuthenticateLoginTest, CorrectPassword) {

    login user = { "john_doe", "secure_password" };
    EXPECT_TRUE(authenticateLogin(user, "secure_password"));
}

TEST(AuthenticateLoginTest, IncorrectPassword) {

    login user = { "jane_doe", "password123" };
    EXPECT_FALSE(authenticateLogin(user, "wrong_password"));
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
