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
#include "User.h"
#include "Message.h"
#include "BBoard.h"
#include <string>
#include <iostream>
#include <vector>
#include <fstream>
#include <stdio.h>
using namespace std;

int main(int argc,char* argv[])
{
    
    
    
	// check commandline arguments 
    // (see Zyante Chapter 7, section 7.7 for explanations and examples)   
    if (argc != 3){
        cout << "ERROR: Invalid program call." << endl
            << "Usage: <program_name> userfile datafile" << endl;
        return 1;
    }
    string userfile(argv[1]);
    string datafile(argv[2]);
   
    BBoard bb("CS12 Bulletin Board");
 
    // load users from file
    if (!bb.load_users(userfile))
    {
        cout << "ERROR: Cannot load users from " << userfile << endl;
        return 1;
    }
     //cout << "************************************" << endl;
    // load messages   
    if (!bb.load_messages(datafile))
    {
        cout << "ERROR: Cannot load messages from " << datafile << endl;
        return 1;
    }
    //cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    bb.login();
    bb.run();
    //cout << "finished run......." << endl;
    // save messages
    if (!bb.save_messages(datafile))
    {
        cout << "ERROR: Cannot save messages to " << datafile << endl;
        return 1;
    }
    
    //cout << "##############################" << endl; 
	return 0;
}