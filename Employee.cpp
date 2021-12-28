#include <iostream>
#include "Employee.h"
using namespace std;

Employee::Employee(string n, string ad, string p_n, string em, string pass, int sl, bool admin, Time* birth, Time* join, Time* leave):Account(n, ad, p_n, em, pass, sl, admin, birth, join, leave){

};

void Employee::EmployeeInfo(){
    cout << "Name: " << name << endl;

}
