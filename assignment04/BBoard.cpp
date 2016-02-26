#include "User.h"
#include "Message.h"
#include "BBoard.h"
#include <string>
#include <iostream>
#include <vector>
#include <fstream>
#include <stdio.h>
using namespace std;


BBoard::BBoard()
{
    title = "Bella's Bulletin Board";
}

BBoard::BBoard(const string &tt1)
{
    title = tt1;
}

void BBoard::setup(const string &input_file)
{
    ifstream infile(input_file.c_str());
    string uname, pw;
    infile >> uname;
    while(uname != "end")
    {
        infile>>pw;
        User new_user(uname,pw);
        user_list.push_back(new_user);
        infile>>uname;
    }
    
    infile.close();
   
}


void BBoard::login()
{
    cout << "Welcome to " << title <<"\'s Amazing Bulletin Board" << endl;

    string uname, pw;
    
    while(1)
    {
        cout << "Enter your username ('Q' or 'q' to quit): ";
        cin >> uname;
        if (uname != "Q" && uname != "q")
        {
            cout << "Enter your password: ";
            cin >> pw;
            bool match = false;
            for(unsigned i = 0; i < user_list.size(); ++i)
            {
                match = user_list.at(i).check(uname,pw);
                if(match)
                    {
                        cout << "Welcome back " << uname << "!";
                    
                        goto here;
                    }
            }
            
            if(match == false)
                cout << "Invalid Username or Password!" << endl;
            
        }
        
        else
        {
            cout << "Bye!"<<endl;
            return;
        }

    }
    
    here:
    current_user = User(uname,pw);
 
}



void BBoard::run()
{
    if (current_user.get_username() == "")
        return;
    bool menu = true;
    string opt;
    while (menu)
    {
        cout << "\nMenu" << endl;
        cout << "  - Display Messages ('D' or 'd')" << endl;
        cout << "  - Add New Message ('N' or 'n')" << endl;
        cout << "  - Quit ('Q' or 'q')" << endl;
        cout << "Choose an action: ";
        cin >> opt;
        if (opt == "D" || opt == "d")
            display();
        else if (opt == "N" || opt == "n")
            add_message();
        else if (opt == "Q" || opt == "q")
            menu = false;
    }
    cout << "Bye!" << endl;
}

void BBoard::add_message()
{
    cout << "Enter Subject: ";
    string subject; 
    getline(cin,subject); 

    cout << "Enter Body: ";
    string body; 
    getline(cin,body);
    
    Message new_Message(current_user.get_username(),subject,body);
    message_list.push_back(new_Message);
    cout << "Message Recorded!" << endl;
}

void BBoard::display() const
{
    if (message_list.size() == 0)
    {
        cout << "\nNothing to Display." << endl;
        return;
    }
    
    
    cout << "\n-----------------------------------------" << endl;
    for (unsigned int i = 0; i < message_list.size(); i++)
    {
        cout << "Message #" << i+1 << ": ";
        message_list.at(i).display();
        cout << "-----------------------------------------" << endl;
    }
}

