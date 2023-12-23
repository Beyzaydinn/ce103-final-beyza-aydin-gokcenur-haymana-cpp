
#include <iostream>
#include <stack>
#include <string>
#include <sstream>
#include <fstream>
#include <stdexcept>
#include "../../event/header/event.h"  
#include "../../event/src/event.cpp"


using namespace std;

int main() {
    int choice = 0;
    // ýn this, we are saying "welcome" to users
    cout << "-------------------------------------------" << endl;
    cout << " You are welcome to GokZa Organization" << endl;
    cout << "-------------------------------------------" << endl;
    
   ofstream file("event_organization.bin", ios::binary | ios::out);
  if (!file.is_open()) {
     cout << "Unable to open the file." << endl;
     return 1;
  }
  while (choice != 6) {
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
                      cout << "This file is private." << endl;
                      break;
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
                  break;
              }
              else {
                  cout << "Unable to open the file." << endl;
                  return 0;
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
      case 4: {
          int trackingChoice;
          progressTracking();
          cout << "Make your choice: ";
          cin >> trackingChoice;

          switch (trackingChoice) {
          case 1: {
              planTimelines();
              cout << "You selected an event time. Is there anything special you would like to add?" << endl;
              cin.ignore(); // clear spaces and newlines
              getline(cin, plan.timelines);
              break;
          }
          case 2: {
              string organize;
              cout << "Is there anything you would like to change? If so, please specify." << endl;
              cin.ignore();  // clear spaces and newlines
              getline(cin, organize);
              break;
          }
          default:
              cout << "Invalid choice. Please try again." << endl;
          }
          break;
      }
      case 5: {
          // the users writing a feedback about this application
          string feed;
          feedback();
          cout << "Please leave feedback if you are satisfied with the service we provide." << endl;
          cout << "Thank you for choosing us. Have a good day!" << endl;
          getline(cin, feed);
          break;
      }
      case 6: {
          // exiting the program
          cout << "Exiting..." << endl;
          return 0;
          break;
      }
      default:
          cout << "Invalid choice. Please try again." << endl;

      }
  }
  file.close();  // Close the file after writing

      return 0;
}