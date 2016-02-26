//  =============== BEGIN ASSESSMENT HEADER ================
/// @file assn<#>/main.cpp 
/// @brief Assignment/Lab <#, e.g. 1,2,3..10> for CS 12 <quarter & year>
///
/// @author <CHaoyun Ma> [chaoyunma10@gmail.com]
/// @date <2.18.2015>
///
/// @par Enrollment Notes 
///     Lecture Section: <e.g. 001>
/// @par
///     Lab Section: <e.g. 022>
/// @par
///     TA: <TA name>
///
/// @par Plagiarism Section
/// I hereby certify that the code in this file
/// is ENTIRELY my own original work.
//  ================== END ASSESSMENT HEADER ===============
#include "IntVector.h"
#include <stdlib.h>
#include <iostream>
using namespace std;

int main()
{
    IntVector a;
    IntVector b(10);
    IntVector c(5,10);
    
    
    
   
    
    cout << "resize c to 1: " << endl;
    c.reserve(15);
    for(unsigned i = 0; i < c.size(); ++i)
        cout << c.at(i) << " ";
    cout << endl;
    
    cout << "resize c to 20 with value 3: " << endl;
    c.reserve(15);
    for(unsigned i = 0; i < c.size(); ++i)
        cout << c.at(i) << " ";
    cout << endl;
    
    cout << "reserve a's cap to 5" << endl;
    cout << "a's original cap is: " << a.capacity() << endl;
    a.reserve(5);
    cout << "a's cap is: " << a.capacity() << endl;
    
    
    return 0;
}