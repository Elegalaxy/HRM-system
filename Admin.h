#ifndef ADMIN_H
#define ADMIN_H
#include "Account.h"
#include <string>

class Admin:public Account{

public:
    Admin(std::string n, std::string ad, std::string p_n, std::string em, std::string pass, int sl, bool admin, Time* birth, Time* join, Time* leave);
    void get_info();
    
};

#endif