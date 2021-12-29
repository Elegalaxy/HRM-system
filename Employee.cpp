#include <iostream>
#include "Employee.h"
using namespace std;

Employee::Employee(string n, string ad, string p_n, string em, string pass, int sl, bool admin, Time* birth, Time* join, Time* leave):Account(n, ad, p_n, em, pass, sl, admin, birth, join, leave){

};

void Employee::EmployeeInfo(){
    cout << "Name: " << name << endl;
    cout << "Address: " << address << endl;
    cout << "Phone Number: " << phone_number << endl;
    cout << "Email: " << email << endl;
    cout << "Password: " << password << endl;
    cout << "Date of Birth: " << dob << endl;
    cout << "Join Date: " << join_date << endl;
    cout << "Leave Date: " << leave_date << endl << endl;
}

void Employee::EmployeeCin(map<string, vector<pair<Time*, Time*>> > &attend){
    attend[email].push_back(make_pair(new Time(), nullptr));
}


void Employee::EmployeeCout(map<string, vector<pair<Time*, Time*>> > &attend){
    attend[email][attend[email].size()-1].second = new Time();
}