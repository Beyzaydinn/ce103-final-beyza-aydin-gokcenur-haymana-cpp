#include "../header/event.h"
#include <stdexcept>
#include <iostream>

using namespace std;
struct login {
    string username;
    string password;
};

struct recording {
    string nameSurname;
    string password;
    string password2;
    string phoneNumber;
    string email;
};

struct choose {
    string type;
    string color;
    string venue;
    string menu;
};


struct tracking {
    string timelines;
};
int mainMenu() {
    cout << endl;
    cout << "Main Menu:\n";
    cout << "1. User Authentication\n";
    cout << "2. Project Setup\n";
    cout << "3. Task Assignment\n";
    cout << "4. Progress Tracking\n";
    cout << "5. Reporting\n";
    cout << "6. Exit\n";
    return 0;
}
// user login and register
int userAuthentication() {
    cout << endl;
    cout << "1. Login \n";
    cout << "2. Register \n";
    cout << "3. Guest Mode \n";
    return 0;
}
// creat the project
int projectSetup() {
    cout << endl;
    cout << "1. Create Event:\n";
    cout << "2. Manage Event:\n";
    return 0;
}
// creat the organization type
int type() {
    cout << endl;
    cout << "1) Wedding" << endl;
    cout << "2) Birthday" << endl;
    cout << "3) Bride" << endl;
    cout << "4) Circumcision" << endl;
    cout << "5) Engagement" << endl;
    cout << "6) Baby Shower" << endl;
    return 0;
}

bool authenticateLogin(const login& user, string password2) {
    return user.password == password2;
}