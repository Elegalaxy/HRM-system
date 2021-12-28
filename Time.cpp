#include "Time.h"
using namespace std;

Time::Time(){
    time_t t = time(0);
    tm* now = localtime(&t);

    Time_date = cons_time(now->tm_mday, now->tm_mon+1, now->tm_year+1900);
    Time_time = cons_time(now->tm_hour, now->tm_min, now->tm_sec);
}

Time::Time(int nul){
    
}

Time::Time(string t){
    Time_date = t.substr(0, 10);
    Time_time = t.substr(11);
}

Time::Time(int f, int s, int t, bool isDate = true){
    string temp = cons_time(f, s, t);
    if(isDate)
        Time_date = temp;
    else
        Time_time = temp;
}

Time::Time(int day, int month, int year, int hr, int mins, int sec){
    Time_date = cons_time(day, month, year);
    Time_time = cons_time(hr, mins, sec);

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

string Time::cons_time(int f, int s, int t){
    return to_string(f)+"-"+to_string(s)+"-"+to_string(t);
}
