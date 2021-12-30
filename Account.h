#ifndef ACCOUNT_H
#define ACCOUNT_H
#include "Time.h"
#include <string>
#include <map>
#include <vector>

class Account{

protected:
    std::string name, address, phone_number, email, password;
    int salary;
    bool isAdmin;
    Time* dob, *join_date, *leave_date;

public:
    //Constructor
    Account();
    Account(std::string n, std::string ad, std::string p_n, std::string em, std::string pass, int sl, bool admin, Time* birth, Time* join, Time* leave);
    
    //Getter
    std::string get_string(std::string n);
    int get_salary();
    bool get_admin();
    Time* get_time(std::string n);

    //Setter
    void set_string(std::string n, std::string data);
    void set_salary(int data);
    void set_admin(bool data);
    void set_time(std::string n, Time* data);

    virtual void get_info();
    virtual void createacc(std::map<std::string, Account*> &db);
    virtual void editacc(std::map<std::string, Account*> &db);
    virtual void deleteacc(std::map<std::string, Account*> &db);
    void check_in(std::map<std::string, std::vector<std::pair<Time*, Time*>> > &attend);
    void check_out(std::map<std::string, std::vector<std::pair<Time*, Time*>> > &attend);

};

#endif