#include <iostream>
#include <fstream>
#include <filesystem>
#include "Admin.h"
#include "Employee.h"
using namespace std;

Admin::Admin(string n, string ad, string p_n, string em, string pass, int sl, bool admin, Time* birth, Time* join, Time* leave):Account(n, ad, p_n, em, pass, sl, admin, birth, join, leave){

};

void Admin::get_info(map<string, Account*> &db){
    map<string, Account*>::iterator info;

    for (info = db.begin(); info != db.end(); info++){
        Account*accinfo = info->second;
        cout << "Name: " << accinfo->get_string("name") << endl;
        cout << "Date of Birth: " << accinfo->get_time("dob")->get_date() << endl;
        cout << "Address: " << accinfo->get_string("address") << endl;
        cout << "Phone number: " << accinfo->get_string("phone_number") << endl;
        cout << "Email: " << accinfo->get_string("email") << endl;
        cout << "Salary: " << accinfo->get_salary() << endl;
        cout << "Admin: " << ((accinfo->get_admin()==true)?"Y":"N") << endl;
        cout << "Join Date: " << accinfo->get_time("join")->get_both() << endl;
        cout << "Leave Date: " << accinfo->get_time("leave")->get_both() << endl << endl;
    }
        
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
    cout << "Format DD-MM-YYYY" << endl;
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
    db[email] = admin;

    // record to db
    ofstream dbFile("Logs/database.txt");

    dbFile << admin->get_string("email") << '\n'
        << admin->get_string("address") << '\n'
        << admin->get_string("phone_number") << '\n'
        << admin->get_string("name") << '\n'
        << admin->get_string("password") << '\n'
        << to_string(admin->get_salary()) << '\n'
        << to_string(admin->get_admin()) << '\n'
        << admin->get_time("dob")->get_both() << '\n'
        << admin->get_time("join")->get_both() << '\n'
        << admin->get_time("leave")->get_both() << '\n' << '\n';

    dbFile.close();

    cout << "Successfully create account" << endl;

}

void Admin::editacc(map<string, Account*> &db){
    string email;
    int choice;
    int n;
    string str;

    cout << "Which account do you want to edit?" << endl;
    cin >> email;

    Account* cur = db[email];
    if(cur == nullptr){
        db.erase(email);
        cout << "Account not exist!" << endl;
    }else{
        cur->get_info(db);
        cout << "What data do you want to edit?" << endl;
        cout << "Name(1), Address(2), Phone Number(3)" << endl;
        cout << "Email(4) Password(5), Salary(6)" << endl;
        cin >> choice;
        cout << "Change to: ";
        (choice == 6)? cin >> n: cin >> str;

        bool succ = true;
        switch (choice){
            case 1:
                cur->set_string("name", str);
                break;
            case 2:
                cur->set_string("address", str);
                break;
            case 3:
                cur->set_string("phone_number", str);
                break;
            case 4:
                cur->set_string("email", str);
                break;
            case 5:
                cur->set_string("password", str);
                break;
            case 6:
                cur->set_salary(n);
                break;
            default:
                succ = false;
                cout << "Data not available!" << endl;
        }

        if(succ)
            cout << "Successfully change data" << endl;

    }

}
void Admin::deleteacc(map<string, Account*> &db){
    string email, sure;
    cout << "Which account do you want to delete?" << endl;
    cout << "Enter by email: " << endl;
    cin >> email;
    cout << "Are you sure you want to delete " << email << " ?(y/n): ";
    cin >> sure;

    if(sure == "y" || sure == "Y"){
        db.erase(email);
        cout << "Successfully delete account" << endl;
    }
}