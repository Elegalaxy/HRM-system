/*
HRM_System by ZeKai Chong and Dowson Kerk
ZeKai Chong: https://github.com/Elegalaxy
Dowson Kerk: https://github.com/DowsonKerk
*/
#include <iostream>
using namespace std;

int main (){
    cout << "Human Resources Management" << endl;
    int choice = 1;
    while(choice !=2)
        cout << "(1)Login" << endl;
        cout << "(2)Exit" << endl;
        cin >> choice;
        cout << endl;

        if(choice == 1)
            login();

    return 0;
    
}


void login(){
    string username;
    string password;
        cout << "(1)Username" << endl;
        cin >> username;
        cout << "(2)Passsword" << endl;
        cin >> password;      
}

