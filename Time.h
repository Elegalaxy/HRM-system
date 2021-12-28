#ifndef TIME_H
#define TIME_H
#include <string>
#include <time.h>

class Time{

private:
    std::string Time_time = ""; //HH-MM-SS
    std::string Time_date = ""; //DD-MM-YYYY
    std::string cons_time(int f, int s, int t);

public:
    Time(); // Create current time
    Time(int f, int s, int t, bool isDate); // Create time obj
    Time(int day, int month, int year, int hr, int mins, int sec); // Create time obj
    std::string get_time();
    std::string get_date();
};

#endif