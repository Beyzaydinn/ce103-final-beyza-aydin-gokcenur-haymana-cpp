#include "../header/event.h"
#include <stdexcept>

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