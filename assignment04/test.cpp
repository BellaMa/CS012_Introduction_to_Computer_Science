#include <string>
#include <iostream>
#include <fstream>
#include "User.h"
#include <vector>
#include <sstream>
using namespace std;

int main(){
    
    vector<User> user_list;
    
    ifstream infile;
    
    infile.open("user.txt");

    if(!infile.is_open())
    {
        cout << "Error opening file" << endl;
    }
    
    string line, uname, pw;
    int i = 0;
    User new_user;
    istringstream instring;
    cout << "working " << endl;
    user_list.
    while(getline(infile,line))
    {
        if(line != "end")
        {
            instring >> uname;
            instring >> pw;
            new_user = User(uname, pw);
            user_list.push_back(new_user);
            //user_list.at(i) = User(uname,pw);
            ++i;
            cout << i << " " << user_list.at(i).get_username();
        }
    }

    
    return 0;
}