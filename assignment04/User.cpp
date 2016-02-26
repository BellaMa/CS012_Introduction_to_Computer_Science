#include "User.h"
#include <string>
#include <iostream>
#include <stdio.h>
using namespace std;

User::User()
{
    username = "";
    password = "";
}

User::User(const string& uname, const string& pass)
{
    username = uname;
    password = pass;
}

string User::get_username() const
{
    return username;
}

bool User::check(const string &uname, const string &pass) const
{
    if(uname == "")
        return false;
    else if(pass == "")
        return false;
    else if(username == uname)
        {
            if(password == pass)
                return true;
        }
    else 
        return false;
        
    return false;
}

void User::set_password(const string &newpass)
{
    password = newpass;
}