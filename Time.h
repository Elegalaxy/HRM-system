#ifndef TIME_H
#define TIME_H
#include <string>
#include <time.h>

class Time{

private:
    std::string Time_time = "NULL"; //HH-MM-SS
    std::string Time_date = "NULL"; //DD-MM-YYYY
    std::string cons_time(int f, int s, int t);
    std::string cons_time(std::string f, std::string s, std::string t);

public:
    Time(); // Create current time
    Time(int nul); // Create nul time
    Time(std::string t); // Create time from log
    Time(std::string f, std::string s, std::string t, bool isDate); // Create time obj
    Time(std::string day, std::string month, std::string year, std::string hr, std::string mins, std::string sec); // Create time obj
    std::string get_time();
    std::string get_date();
    std::string get_both();
};

#endif