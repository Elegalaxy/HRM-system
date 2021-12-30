#include <iostream>
#include "Admin.h"
#include "Employee.h"
using namespace std;

Admin::Admin(string n, string ad, string p_n, string em, string pass, int sl, bool admin, Time* birth, Time* join, Time* leave):Account(n, ad, p_n, em, pass, sl, admin, birth, join, leave){

};

void Admin::get_info(){

}

void Admin::createacc(map<string, Account*> &db){ 
    string name, address, phone_number, email, password, salary ,isAdmin, year, month, date;

    cout << "Name: ";
    cin >> name;
    cout << "Address: ";
    cin >> address;
    cout << "Phone Number: ";
    cin >> phone_number;
    cout << "Email: ";
    cin >> email;
    cout << "Password: ";
    cin >> password;
    cout << "Format DD-MM-YYYY";
    cout << "Date of Birth(Date): ";
    cin >> date;
    cout << "Date of Birth(Month): ";
    cin >> month;
    cout << "Date of Birth(Year): ";
    cin >> year;
    cout << "Salary: ";
    cin >> salary;
    cout << "Admin(true/false): ";
    cin >> isAdmin;
    Account*admin;
    if (isAdmin == "true") 
        admin = new Admin(name, address, phone_number, email, password,stoi(salary),(isAdmin == "true"), new Time(date, month, year, true), new Time(), new Time(0));
    else
        admin = new Employee(name, address, phone_number, email, password,stoi(salary),(isAdmin == "true"), new Time(date, month, year, true), new Time(), new Time(0));
    db[email]= admin;
}

void Admin::editacc(){

}
void Admin::deleteacc(){

}