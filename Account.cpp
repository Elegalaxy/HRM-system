#include "Account.h"
#include <iostream>
using namespace std;

//Constructor

Account::Account(): name{""}, address{""}, phone_number{""}, email{""}, password{""}, salary{0}, isAdmin{false}, dob{new Time(nullptr)}, join_date{new Time(nullptr)}, leave_date{new Time(nullptr)} {};

Account::Account(std::string n, std::string ad, std::string p_n, std::string em, std::string pass, int sl, bool admin, Time* birth, Time* join, Time* leave): name{n}, address{ad}, phone_number{p_n}, email{em}, password{pass}, salary{sl}, isAdmin{admin}, dob{birth}, join_date{join}, leave_date{leave} {};

//Getter

string Account::get_string(std::string n);

int Account::get_salary();

bool Account::get_admin();

Time* Account::get_time(std::string n);


//Setter

void set_string(std::string n, string data);

void set_salary(int data);

void set_admin(bool data);

void set_time(std::string n);
