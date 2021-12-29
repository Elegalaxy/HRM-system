#include <iostream>
#include "Employee.h"
using namespace std;

Employee::Employee(string n, string ad, string p_n, string em, string pass, int sl, bool admin, Time* birth, Time* join, Time* leave):Account(n, ad, p_n, em, pass, sl, admin, birth, join, leave){

};

void Employee::get_info(){
    cout << "Name: " << name << endl;
    cout << "Address: " << address << endl;
    cout << "Phone Number: " << phone_number << endl;
    cout << "Email: " << email << endl;
    cout << "Password: " << password << endl;
    cout << "Date of Birth: " << dob << endl;
    cout << "Join Date: " << join_date << endl;
    cout << "Leave Date: " << leave_date << endl << endl;
}
