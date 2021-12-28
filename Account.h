#ifndef ACCOUNT_H
#define ACCOUNT_H
#include "Time.h"
#include <string>

class Account{

private:
    std::string name, address, phone_number, email, password;
    int salary;
    bool isAdmin;
    Time* dob, *join_date, *leave_date;

public:
    Account(): name{""}, address{""}, phone_number{""}, email{""}, password{""}, salary{0}, isAdmin{false}, dob{new Time(nullptr)}, join_date{new Time(nullptr)}, leave_date{new Time(nullptr)} {};
    Account(std::string n, std::string ad, std::string p_n, std::string em, std::string pass, int sl, bool admin, Time* birth, Time* join, Time* leave): name{n}, address{ad}, phone_number{p_n}, email{em}, password{pass}, salary{sl}, isAdmin{admin}, dob{birth}, join_date{join}, leave_date{leave} {};
    
    //Getter
    std::string get_string(std::string n);
    int get_salary();
    bool get_admin();
    Time* get_time(std::string n);

};

#endif