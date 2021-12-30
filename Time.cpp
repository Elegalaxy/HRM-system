#include "Time.h"
#include <iostream>
using namespace std;

Time::Time(){
    time_t t = time(0);
    tm* now = localtime(&t);

    string d = fix(now->tm_mday);
    string m = fix(now->tm_mon+1);
    string hr = fix(now->tm_hour);
    string mins = fix(now->tm_min);
    string sec = fix(now->tm_sec);


    Time_date = cons_time(d, m, to_string(now->tm_year+1900), true);
    Time_time = cons_time(hr, mins, sec, false);
}

Time::Time(int nul){
    Time_date = cons_time("00", "00", "0000", true);
    Time_time = cons_time("00", "00", "00", false);
}

Time::Time(string t){
    Time_date = t.substr(0, 10);
    Time_time = t.substr(11);
}

Time::Time(string f, string s, string t, bool isDate = true){
    string temp = cons_time(f, s, t, isDate);
    if(isDate)
        Time_date = temp;
    else
        Time_time = temp;
}

Time::Time(string day, string month, string year, string hr, string mins, string sec){
    Time_date = cons_time(day, month, year, true);
    Time_time = cons_time(hr, mins, sec, false);

}

string Time::get_time(){
    return Time_time;
}

string Time::get_date(){
    return Time_date;
}

string Time::get_both(){
    return Time_date+","+Time_time;
}

string Time::cons_time(string f, string s, string t, bool isDate){
    return f+ ((isDate)?"-" :":") +s+ ((isDate)?"-" :":") +t;
}

string Time::fix(int t){
    string res = to_string(t);

    if(res.length() == 1)
        res = "0"+res;

    return res;
}
