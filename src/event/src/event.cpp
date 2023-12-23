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
// create the organization menu
int menu() {
    cout << endl;
    cout << "1. Food Menu" << endl;
    cout << "2. Cake Menu" << endl;
    return 0;
}
// create the organization color type
int color() {
    cout << endl;
    cout << "1. Pink and Blue\n";
    cout << "2. Red and Black\n";
    cout << "3. Cream color and Brown\n";
    cout << "4. White and Black\n";
    return 0;
}
// create the organization place
int venue() {
    cout << endl;
    cout << "1. Indoor event hall\n";
    cout << "2. Beach Side\n";
    cout << "3. Countryside Organization\n";
    return 0;
}
// List the user's choice
int userPlan() {
    choose create;
    cout << endl;
    cout << "Your type: " << create.type << endl;
    cout << "Your venue: " << create.venue << endl;
    cout << "Your color type: " << create.color << endl;
    cout << "Your menu: " << create.menu << endl;
    return 0;
}
// planning about attendees 
int taskAssignment() {
    cout << endl;
    cout << "1. Register Attendees: \n";
    cout << "2. Track Attendees: \n";
    return 0;
}
// organization time
int progressTracking() {
    cout << endl;
    cout << "1. Plan Timelines\n";
    cout << "2. Organize Activities\n";
    return 0;
}
// plan timelines
int planTimelines() {
    cout << endl;
    cout << "1. Morning Event (09.00-13.00) " << endl;
    cout << "2. Noon Event (13.00-18.00) " << endl;
    cout << "3. Evening Event (18.00-22.00) " << endl;
    return 0;
}

// make a feedback
int feedback() {
    cout << endl;
    cout << "Gather Feedback" << endl;
    return 0;
}
// check the user login
bool authenticateLogin(const login& user, string password2) {
    return user.password == password2;
}