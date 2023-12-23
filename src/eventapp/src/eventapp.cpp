
#include <iostream>
#include <stack>
#include <string>
#include <sstream>
#include <fstream>
#include <stdexcept>
#include "../../event/header/event.h"  

using namespace std;

int main() {
    int choice;
    // ýn this, we are saying "welcome" to users
    cout << "-------------------------------------------" << endl;
    cout << " You are welcome to GokZa Organization" << endl;
    cout << "-------------------------------------------" << endl;
    
        ofstream file("event_organization.bin", ios::binary | ios::out);
        if (!file.is_open()) {
            cout << "Unable to open the file." << endl;
            return 1;
        }
        while (choice != 6);
        mainMenu();
        cout << "Make your choice: ";
        cin >> choice;

        login user;
        recording store;
        choose create;
        tracking plan;

        switch (choice) {
        case 1: {
            int loginChoice;
            userAuthentication();
            cout << "Make your choice: ";
            cin >> loginChoice;

            switch (loginChoice) {
            case 1: {
                // the users are making login
                cout << "User Name: ";
                cin >> user.username;
                cout << "Password: ";
                cin >> user.password;

                if (authenticateLogin(user, user.password)) {
                    // If the registered information and the entered information are equal
                    cout << "Login is successful!" << endl;
                    if (file.is_open()) {
                        file << "USER INFORMATION" << endl;
                        file << "Username: " << user.username << endl;
                        file << "Password: " << user.password << endl; // Fix here, removed extra character "Ý"
                        file << "------------------------" << endl;
                        file.close();
                        cout << "This file is private." << endl;
                        return 0;
                    }
                    else {
                        cout << "Unable to open the file." << endl;
                        return 0;
                    }
                }
                else {
                    // If the registered information and the entered information are not equal
                    cout << "Login failed. Please try again." << endl;
                    break;
                }
            }
            case 2: {
                // the users are making register
                cout << "\nYour user name: ";
                cin >> store.nameSurname;
                cout << "\nYour password: ";
                cin >> store.password2;
                cout << "\nYour phone number: ";
                cin >> store.phoneNumber;
                cout << "\nYour e-mail: ";
                cin >> store.email;
                cout << "\n Your information is saved. Please login." << endl;

                if (file.is_open()) {
                    file << "USER REGISTER" << endl;
                    file << "Username: " << store.nameSurname << endl;
                    file << "Password: " << store.password2 << endl;
                    file << "Phone number: " << store.phoneNumber << endl;
                    file << "Email: " << store.email << endl;
                    file << "------------------------------" << endl;
                    file.close();  // Close the file after writing
                }
                else {
                    cout << "Unable to open the file." << endl;
                }
                break;
            }
            case 3: {
                // you are in the guest mode.
                cout << "You are in guest mode." << endl;
                break;
            }
            default:
                cout << "Invalid choice. Please try again." << endl;
            }
            break;
        }
        case 2: {
            int eventChoice;
            projectSetup();
            cout << "Make your choice: ";
            cin >> eventChoice;

            switch (eventChoice) {
            case 1: {
                type();
                cout << "Make your choice: ";
                cin >> create.type;

                menu();
                cout << "Make your choice: ";
                cin >> create.menu;

                color();
                cout << "Make your choice: ";
                cin >> create.color;

                venue();
                cout << "Make your choice: ";
                cin >> create.venue;
                break;
            }
            case 2: {
                userPlan();
                break;
            }
            default:
                cout << "Invalid choice. Please try again." << endl;
            }
            break;
        } 
        case 3: {
            int attendees;
            taskAssignment();
            cout << "Make your choice: ";
            cin >> attendees;
            switch (attendees) {
            case 1: {
                int count;
                cout << "Please enter the attendees number: ";
                cin >> count;

                // Consume the newline character left in the buffer
                cin.ignore();

                for (int i = 0; i < count; i++) {
                    string fullname; // Change the variable type to string
                    cout << "\n  Enter attendee's name and surname: ";
                    getline(cin, fullname);
                }
                break;
            }
            case 2: {


                break;
            }
            default:
                cout << "Invalid choice. Please try again." << endl;
            }
            break;
        }


}