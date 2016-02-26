//  =============== BEGIN ASSESSMENT HEADER ================
/// @file assn<#7>/BBoard.cpp 
/// @brief Assignment/Lab <#7> for CS 12 <winter & 2015>
///
/// @author <CHaoyun Ma> [chaoyunma10@gmail.com]
/// @date <3.13.2015>
///
/// @par Enrollment Notes 
///     Lecture Section: <001>
/// @par
///     Lab Section: <022>
/// @par
///     TA: <TA name>
///
/// @par Plagiarism Section
/// I hereby certify that the code in this file
/// is ENTIRELY my own original work.
//  ================== END ASSESSMENT HEADER ===============
#include "User.h"
#include "Message.h"
#include "BBoard.h"
#include "Topic.h"
#include "Reply.h"
#include <string>
#include <iostream>
#include <vector>
#include <fstream>
#include <stdio.h>
#include <sstream>
using namespace std;


BBoard::BBoard()
{
    title = "Bella's Bulletin Board";
    current_user = 0;
}

BBoard::BBoard(const string &tt1)
{
    title = tt1;
    current_user = 0;
}

BBoard::~BBoard()
{
    for(unsigned i = 0; i < message_list.size(); ++i)
        delete message_list.at(i);
}

bool BBoard::load_users(const string &userfile)
{
    ifstream infile(userfile.c_str());
    if(infile.is_open())
    {
        string uname, pw;
        infile >> uname;
        while(uname != "end")
        {
            infile >> pw;
            User new_user(uname ,pw);
            user_list.push_back(new_user);
            infile >> uname;
        }
        infile.close();

        return true;
    }
    
    return false;
}



bool BBoard::load_messages(const string &datafile)  
{
    //to constuct a message
    unsigned id_reply, id_topic;
    string subject_reply, subject_topic, subject;
    //vector<string> body_reply, body_topic;
    string author_reply, author_topic;
    string children_reply, children_topic;
    string discard, body_temp, body_string, body;
    vector<string> child_id(300); //at pos id, it stores all its replies id
    
    string one_line;
    //to parse a line
    //stringstream is_line;
    
    //read in from datafile to construct messages
    ifstream infile(datafile.c_str());
    if(infile.is_open())
    {
        infile >> one_line;
        while(getline(infile,one_line))
        {
            //to construct a topic meassage
            if(one_line == "<begin_topic>")
            {
                getline(infile,one_line);
                while(one_line != "<end>")//????
                {
                    //is_line << one_line;
                    stringstream is_line(one_line);
                    //just the first word in that line
                    is_line >> discard;
                    if(discard == ":id:")
                    {
                        is_line >> id_topic; 
                    } 
                    else if(discard == ":subject:")
                    {
                        getline(is_line, subject_topic); //include space!!!!
                        subject = subject_topic.substr(1); // remove the first space(at beg)
                    }
                    else if(discard == ":from:")
                    {
                        is_line >> author_topic;
                    }
                    else if(discard == ":children:")
                    {
                        if(id_topic < child_id.size())
                            getline(is_line, child_id.at(id_topic - 1)); 
                        else
                        {
                            int i = id_topic - child_id.size();
                            while(--i)
                                child_id.push_back(0);
                            getline(is_line, child_id.at(id_topic - 1)); 
                        }
                    }
                    else if(discard == ":body:")
                    {
                        vector<string> body_topic;
                        body_string = "";
                        
                        getline(is_line, body_temp);
                        body_topic.push_back(body_temp);
                        getline(infile,one_line);
                        while(one_line != "<end>")
                        {
                            body_topic.push_back(one_line);
                            getline(infile,one_line);
                        }
                        int i = body_topic.size();
                        if(i != 0)
                        {   
                            for(int j = 0; j < i; ++j )
                                body_string += (body_topic.at(j) + '\n');
                        }
                        
                        body = body_string.substr(1);
                        
                        Topic* new_topic = new Topic(author_topic, subject, body, id_topic);
                        message_list.push_back(new_topic);
                        
                        break;
                    }
                    //for the loop~~~
                    getline(infile, one_line);
                }
            }
            
            
            
            
            //to constuct a reply
            if(one_line == "<begin_reply>")
            {
                getline(infile,one_line);
                while(one_line != "<end>")
                {
                    //is_line << one_line;
                    stringstream is_line(one_line);
                    //just the first word in that line
                    is_line >> discard;
                    if(discard == ":id:")
                    {
                        is_line >> id_reply; 
                    } 
                    else if(discard == ":subject:")
                    {
                        getline(is_line, subject_reply); //include space!!!!
                        subject = subject_reply.substr(1);
                    }
                    else if(discard == ":from:")
                    {
                        is_line >> author_reply;
                    }
                    else if(discard == ":children:")
                    {
                        if(id_reply < child_id.size())
                            getline(is_line, child_id.at(id_reply - 1)); 
                        else
                        {
                            int i = id_reply - child_id.size();
                            while(--i)
                                child_id.push_back(0);
                            getline(is_line, child_id.at(id_reply - 1)); 
                        }
                    }
                    else if(discard == ":body:")
                    {
                        vector<string> body_reply;
                        body_string = "";
                        
                        getline(is_line, body_temp);
                        body_reply.push_back(body_temp);
                        getline(infile,one_line);
                        while(one_line != "<end>")
                        {
                            body_reply.push_back(one_line);
                            getline(infile,one_line);
                        }
                        int i = body_reply.size();
                        if(i != 0)
                        {   
                            
                            for(int j = 0; j < i; ++j )
                                body_string += (body_reply.at(j) + '\n');
                        }
                        
                        body = body_string.substr(1);
                        
                        Reply* new_reply = new Reply(author_reply, subject, body, id_reply);
                        message_list.push_back(new_reply);
                       
                    
                        break;
                    }
                    //for the loop~~~
                    getline(infile, one_line);
                }
            }
            
            
        }
        
        
        for(unsigned id_pos = 0; id_pos < message_list.size(); ++id_pos)
        {
            string id_string = child_id.at(id_pos);
            stringstream id_stream(id_string);
            unsigned id_child;
            while(id_stream >> id_child)
                message_list.at(id_pos)->add_child(message_list.at(id_child - 1));
        }
        
        
        infile.close();
        
    
        return true;  
    }
    
    return false;
}





bool BBoard::save_messages(const string &datafile)
{
    ofstream outfile(datafile.c_str());
    if(outfile.is_open())
    {
        
        for(unsigned i = 0; i < message_list.size(); ++i)
        {
            outfile << message_list.at(i)->to_formatted_string();
        }
        
        outfile.close();
        
        return true;
    }
    return false;
}




void BBoard::login()
{
    cout << "Welcome to " << title <<"\'s Amazing Bulletin Board" << endl;

    User user;
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
                        cout << "Welcome back " << uname << "!" << endl;
                        user = user_list.at(i);
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
    current_user = &user;
 
}



void BBoard::run()
{
    if (current_user->get_username() == "")
        return;
    bool menu = true;
    string opt;
    while (menu)
    {
        cout << "\nMenu" << endl;
        cout << "  - Display Messages ('D' or 'd')" << endl;
        cout << "  - Add New Topic ('N' or 'n')" << endl;
        cout << "  - Add Reply to a Topic ('R' or 'r')" << endl;
        cout << "  - Quit ('Q' or 'q')" << endl;
        cout << "Choose an action: ";
        cin >> opt;
        if (opt == "D" || opt == "d")
            display();
        else if (opt == "N" || opt == "n")
            add_topic();
        else if (opt == "R" || opt == "r")
            add_reply();
        else if (opt == "Q" || opt == "q")
            menu = false;
    }
    cout << "Bye!" << endl;
}

void BBoard::add_topic()
{
    cout << "Enter Subject: ";
    string subject; 
    getline(cin,subject); 

    cout << "Enter Body: ";
    string body, tem; 
    while(getline(cin,tem))
    {
        body += (tem + '\n');
        if(tem == "")
        break;
    }
    
    unsigned id = message_list.size();
    string author = current_user->get_username();
    
    Topic *new_topic = new Topic(author, subject, body, id);
    message_list.push_back(new_topic);

}

void BBoard::display() const
{
    if (message_list.size() == 0)
    {
        cout << "\nNothing to Display." << endl;
        return;
    }
    
    
    cout << "\n-----------------------------------------" << endl;
    for (unsigned i = 0; i < message_list.size(); i++)
    {
        
        if(!(message_list.at(i)->is_reply())) {
            message_list.at(i)->print(0);
            cout << "-----------------------------------------" << endl;
        }
        
    }
}

void BBoard::add_reply()
{
    cout << "Enter Message ID (-1 for Menu): ";
    int id_topic;
    cin >> id_topic;
    while(id_topic != -1)
    {
        if((unsigned) id_topic > message_list.size())
        {    
            cout << "Invalid Message ID!!";
            cin >> id_topic;
        }
        else
            break;
    }
    if(id_topic == -1)
        return;
    

    string topic_sub, prefix, subject;
    topic_sub = message_list.at(id_topic)->get_subject();
    prefix = "Re: ";
    subject = prefix + topic_sub;
    

    cout << "Enter Body: ";
    string body, tem; 
    while(getline(cin,tem))
    {
        body += (tem + '\n');
        if(tem == "")
        break;
    }
    
    unsigned id = message_list.size();
    string author = current_user->get_username();
    
    Reply *new_reply = new Reply(author, subject, body, id);
    message_list.push_back(new_reply);
    
    message_list.at(id_topic)->add_child(new_reply);

}
