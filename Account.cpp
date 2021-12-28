#include "Account.h"
#include <iostream>
using namespace std;

//Constructor

Account::Account(): name{""}, address{""}, phone_number{""}, email{""}, password{""}, salary{0}, isAdmin{false}, dob{new Time(0)}, join_date{new Time(0)}, leave_date{new Time(0)} {};

Account::Account(string n, string ad, string p_n, string em, string pass, int sl, bool admin, Time* birth, Time* join, Time* leave): name{n}, address{ad}, phone_number{p_n}, email{em}, password{pass}, salary{sl}, isAdmin{admin}, dob{birth}, join_date{join}, leave_date{leave} {};

//Getter

string Account::get_string(string n){
    if(n == "name")
        return name;
    else if(n == "address")
        return address;
    else if(n == "phone_number")
        return phone_number;
    else if(n == "email")
        return email;
    else if(n == "password")
        return password;

    return "ERROR";
}

int Account::get_salary(){
    return salary;
}

bool Account::get_admin(){
    return isAdmin;
}

Time* Account::get_time(string n){
    if(n == "dob")
        return dob;
    else if(n == "join")
        return join_date;
    else if(n == "leave")
        return leave_date;

    return nullptr;
}


//Setter

void Account::set_string(string n, string data){
    if(n == "name")
        name = data;
    else if(n == "address")
        address= data;
    else if(n == "phone_number")
        phone_number= data;
    else if(n == "email")
        email= data;
    else if(n == "password")
        password= data;
}

void Account::set_salary(int data){
    salary = data;
}

void Account::set_admin(bool data){
    isAdmin = data;
}

void Account::set_time(string n, Time* data){
    if(n == "dob")
        dob = data;
    else if(n == "join")
        join_date = data;
    else if(n == "leave")
        leave_date = data;
}