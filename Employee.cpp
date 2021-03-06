#include <iostream>
#include "Employee.h"
using namespace std;

Employee::Employee(string n, string ad, string p_n, string em, string pass, int sl, bool admin, Time* birth, Time* join, Time* leave):Account(n, ad, p_n, em, pass, sl, admin, birth, join, leave){

};

void Employee::get_info(std::map<std::string, Account*> &db){
    cout << "Name: " << name << endl;
    cout << "Address: " << address << endl;
    cout << "Phone Number: " << phone_number << endl;
    cout << "Email: " << email << endl;
    cout << "Password: " << password << endl;
    cout << "Date of Birth: " << dob->get_date() << endl;
    cout << "Join Date: " << join_date->get_both() << endl;
    cout << "Leave Date: " << leave_date->get_both() << endl << endl;
}
