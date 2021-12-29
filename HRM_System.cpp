/*
HRM_System by ZeKai Chong and Dowson Kerk
ZeKai Chong: https://github.com/Elegalaxy
Dowson Kerk: https://github.com/DowsonKerk
*/
#include <iostream>
#include <fstream>
#include <filesystem>
#include <string>
#include <map>
#include <vector>
#include "Admin.h"
#include "Employee.h"
using namespace std;
using namespace filesystem;

void init(map<string, Account*> &db, map<string, vector< pair<Time*, Time*> > > &att){
    // Folder path
    path dirP{"Logs"};
    if(exists(dirP)){ // If folder exist
        string curLine;

        // Import database

        ifstream dbFile("database.txt");
        int cur = 0;

        // 0-4
        std::string email, address, phone_number, name, password;
        // 5
        int salary;
        // 6
        bool isAdmin;
        // 7-9
        Time* dob, *join_date, *leave_date;

        while(getline(dbFile, curLine)){
            if(curLine.empty()){
                cur = 0;
                if(isAdmin)
                    db[email] = new Admin(name, address, phone_number, email, password, salary, isAdmin, dob, join_date, leave_date);
                else
                    db[email] = new Employee(name, address, phone_number, email, password, salary, isAdmin, dob, join_date, leave_date);
            }else{
                if(cur == 0)
                    email = curLine;
                else if(cur == 1)
                    address = curLine;
                else if(cur == 2)
                    phone_number = curLine;
                else if(cur == 3)
                    name = curLine;
                else if(cur == 4)
                    password = curLine;
                else if(cur == 5)
                    salary = stoi(curLine);
                else if(cur == 6)
                    isAdmin = (curLine == "true");
                else if(cur == 7)
                    dob = new Time(curLine);
                else if(cur == 8)
                    join_date = new Time(curLine);
                else if(cur == 9)
                    leave_date = new Time(curLine);

                cur++;
            }
        }

        dbFile.close();

        // Import attendances
        curLine = "";
        ifstream attFile("attendances.txt");

        Time *st, *ed;
        email = "";
        cur = 0;

        while(getline(dbFile, curLine)){
            if(curLine.empty()){
                cur = 0;
                att[email].push_back({st, ed});
            }else if(cur == 0){
                email = curLine;
                cur++;
            }else{
                st = new Time(curLine.substr(0, 19));
                ed = new Time(curLine.substr(20));
            }
        }

        attFile.close();

    }else{ // If folder not exist
        create_directory(dirP); // Create folder
    }
}

void onQuit(map<string, Account*> &db, map<string, vector< pair<Time*, Time*> > > &att){
    // Write to database
    ofstream dbFile("Logs/database.txt");
    
    // email
    // address
    // phone_number
    // name
    // password
    // salary
    // admin
    // dob
    // join
    // leave
    // 

    for(auto ppl:db){
        Account* cur = ppl.second;
        dbFile << cur->get_string("email") << '\n'
                << cur->get_string("address") << '\n'
                << cur->get_string("phone_number") << '\n'
                << cur->get_string("name") << '\n'
                << cur->get_string("password") << '\n'
                << to_string(cur->get_salary()) << '\n'
                << to_string(cur->get_admin()) << '\n'
                << cur->get_time("dob")->get_both() << '\n'
                << cur->get_time("join")->get_both() << '\n'
                << cur->get_time("leave")->get_both() << '\n' << '\n';
    }

    dbFile.close();

    // Write to attendances
    ofstream attFile("Logs/attendances.txt");
    
    // email
    // DD-MM-YYYY,HH-MM-SS DD-MM-YYYY,HH-MM-SS (start end)
    // DD-MM-YYYY,HH-MM-SS DD-MM-YYYY,HH-MM-SS
    // ....
    //
    
    for(auto at:att){
        attFile << at.first << '\n'; // email
        for(auto times:at.second){
            attFile << times.first->get_both() << ' '; // Start date and time
            attFile << times.second->get_both() << '\n'; // End date and time
        }
    }

    attFile.close();

}

int main (){
    map<string, Account*> db; // Email, Account
    map<string, vector<pair<Time*, Time*>> > att; //email, attendances, <Start, End>

    init(db, att);

    cout << "Human Resources Management System" << endl;
    cout << "Choose 1 to Proceed and Choose 2 to Exit the system" << endl;
    int choice = 1;
    while(choice !=2){
        cout << "(1)Login" << endl;
        cout << "(2)Exit" << endl;
        cin >> choice;
        cout << endl;

        if(choice == 1)
            login(db, att);
    }

    onQuit(db, att);
    return 0;
}


void login(map<string, Account*>&db, map<string, vector<pair<Time*, Time*>> > &att){
    string email;
    string password;
        cout << "Please enter Your Email: " << endl;
        cin >> email;
        cout << "Please enter Your Passsword: " << endl;
        cin >> password; 
        system("clear");
        Account*currentacc = db[email];
        if (currentacc != nullptr && currentacc->get_string("password") == password ){
            currentacc->check_in(att); 
            cout <<"Welcome to Human Resources Management System," << currentacc->get_string("name")<< "." <<endl;
            int choice= 1;
            while (choice !=0){
                cout << "(1)Account Info" << endl;
                if (currentacc->get_admin() == true){
                    cout << "(2)Create Account" << endl;
                    cout << "(3)Edit Account" << endl;
                    cout << "(4)Delete Account" << endl;
                } 
                cout << "(0)Exit" << endl;

                cin >> choice;
                cout << endl;
                
                if(choice == 1){
                    currentacc->get_info();
                }
                else if (currentacc->get_admin() == true){
                    if(choice == 2)
                        currentacc->createacc();
                    else if(choice == 3)
                        currentacc->editacc();
                    else if(choice == 4)
                        currentacc->deleteacc();    
                }
            }
        currentacc->check_out(att);              
        }
        
}

