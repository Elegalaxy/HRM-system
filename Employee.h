#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include "Account.h"
#include <string>
#include <map>
#include <vector>

class Employee:public Account{

public:
    Employee(std::string n, std::string ad, std::string p_n, std::string em, std::string pass, int sl, bool admin, Time* birth, Time* join, Time* leave);
    void EmployeeInfo();
    void EmployeeCin(map<string, vector<pair<Time*, Time*>> > &attend);
    void EmployeeCout(map<string, vector<pair<Time*, Time*>> > &attend);
};

#endif