#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include "Account.h"
#include <string>

class Employee:public Account{

public:
    Employee(std::string n, std::string ad, std::string p_n, std::string em, std::string pass, int sl, bool admin, Time* birth, Time* join, Time* leave);
    void get_info();

};

#endif