#ifndef TIME_H
#define TIME_H
#include <string>
#include <time.h>

class Time{

private:
    std::string time; //HH-MM-SS
    std::string date; //DD-MM-YYYY

public:
    Time();
    Time();
    std::string get_time();
};

#endif