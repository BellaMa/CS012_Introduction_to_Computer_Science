#ifndef __BBOARD_H__
#define __BBOARD_H__

#include "User.h"
#include "Message.h"

#include <string>
#include <iostream>
#include <vector>
#include <fstream>
#include <stdio.h>
using namespace std;

class BBoard
{
    private:
        string title; 
        /*title of the board; initialized via constructor */
        vector<User> user_list;
        /* list of members; initially empty, then populated via setup() */
        User current_user; 
        /* user who is currently logged in; initialized by c'tor to 
 		the default User, then set via login() */
        vector<Message> message_list;
        /* list of messages; initially empty */
    
    public:
        /* default constructor that creates a board with a default title, 
        empty user & message lists, and the "default" User */
        BBoard( );
        /* same as default c'tor, except that it sets the title of the board. */
        BBoard( const string &ttl );
        /* imports all the authorized users from an input file, 
        storing them as User objects in the vector user_list
        The name of the input file is passed in as a parameter 
        to this function.  */
        void setup( const string &input_file );
        /* asks for and validates current user/password
        This function asks for a username and password, 
        and checks the user_list vector  for a matching User. */
        void login( );
        /* This function contains the main loop of the BBoard. */
        void run( );
        
    private:
        /* This function would be used by the interface function run. 
        It displays all messages in message_list. */
        void display() const;
        /* This function would be used by the interface function run. 
        It asks the user to input a message. Every message includes 
        a subject line and a message line (both are single lines, 
        so you can ignore newlines). */
        void add_message();
        
    
        
        
};


#endif