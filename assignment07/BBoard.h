//  =============== BEGIN ASSESSMENT HEADER ================
/// @file assn<#7>/main.cpp 
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

#ifndef __BBOARD_H__
#define __BBOARD_H__

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

class BBoard
{
    private:
        string title; 
        vector<User> user_list;
        const User* current_user; 
        vector<Message*> message_list;

    public:
        BBoard( );
        BBoard( const string &ttl );
        
        ~BBoard(); //new!
        
        //void setup( const string &input_file ) changed into:
        bool load_users (const string &userfile);
    
        bool load_messages(const string &datafile); //new!
        bool save_messages(const string &datafile); //new!
        
        void login( ); //major changes!!
       
        void run( );
        
    private:
        
        void display() const; //big changes
        
        void add_topic();
        
        void add_reply();
        
    
        
        
};


#endif



/*
<begin_topic>
:id: 2
:subject: Your favorite TV show
:from: ricq7
:children: 3 5
:body: So guys, what is your favorite tv show?
<end>

******** without children
<begin_topic>
:id: 10
:subject: Towel Day
:from: messi
:body: Bring your towels on May 25.
See here: http://www.towelday.org/
<end>

<begin_reply>
:id: 3
:subject: Re: Your favorite TV show
:from: mike
:children: 4
:body: Game of Thrones is an awesome show but there are too 
many characters to remember.
We even did not see half of the families and still at least 20 
important characters are introduced already.
Is there anyplace that I can read about the characters?
<end>

******** without children
<begin_reply>
:id: 7
:subject: Re: Re: Your favorite TV show
:from: jenny
:body: The cat!
Colin Mochrie is hilarious.
<end>

*/