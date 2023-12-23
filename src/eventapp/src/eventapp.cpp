
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




}