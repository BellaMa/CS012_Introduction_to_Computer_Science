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
#ifndef __USER_H__
#define __USER_H__


#include <string>
using namespace std;
  class User
  {
    private:
      string username;
      string password;
 
    public:
      //creates a user with empty name and password.
      User();

      // creates a user with given username and password.
      User(const string& uname, const string& pass);

      //returns the username
      string get_username() const;
 
      // returns true if the stored username/password matches with the
      // parameters. Otherwise returns false.
      // Note that, even though a User with empty name and password is 
      // actually a valid User object (it is the default User), this 
      // function must still return false if given a empty uname string.
      bool check(const string &uname, const string &pass) const;
 
      // sets a new password. This function will not be used in the 
      // current assignment.
      void set_password(const string &newpass);
  };
 
  //end inc guards
  #endif