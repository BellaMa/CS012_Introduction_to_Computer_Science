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
    
    cout << "c.at(1): " << c.at(1) << endl;
    
    cout << "c: " << endl;
    for(unsigned i = 0; i < c.size(); ++i)
        cout << c.at(i) << " ";
    cout << endl;
    
    c.insert(1,5);
    cout << "c.insert(1,5): " << endl;
    for(unsigned i = 0; i < c.size(); ++i)
        cout << c.at(i) << " ";
    cout << endl;

    c.erase(1);
    cout << "c.erase(1) " << endl;
    for(unsigned i = 0; i < c.size(); ++i)
        cout << c.at(i) << " ";
    cout << endl;
    
    cout << "c.front: " << c.front() << endl;
    cout << "c.back: " << c.back() << endl;
    
    cout << "assign c to size 10 with value 1 " << endl;
    c.assign(10,1);
    for(unsigned i = 0; i < c.size(); ++i)
        cout << c.at(i) << " ";
    cout << endl;
    
    cout << "c.push_back(2): " << endl;
    c.push_back(2);
    for(unsigned i = 0; i < c.size(); ++i)
        cout << c.at(i) << " ";
    cout << endl;
    
    cout << "c.pop_back: " << endl;
    c.pop_back();
    for(unsigned i = 0; i < c.size(); ++i)
        cout << c.at(i) << " ";
    cout << endl;
    
    cout << "clear b: " << endl;
    cout << "b's original size: " << b.size() << endl;
    b.clear();
    cout << "b's size: " << b.size() << endl;
    
    cout << "resize c to 15: " << endl;
    c.resize(15);
    for(unsigned i = 0; i < c.size(); ++i)
        cout << c.at(i) << " ";
    cout << endl;
    
    cout << "resize c to 20 with value 3: " << endl;
    c.resize(20,3);
    for(unsigned i = 0; i < c.size(); ++i)
        cout << c.at(i) << " ";
    cout << endl;
    
    cout << "reserve a's cap to 5" << endl;
    cout << "a's original cap is: " << a.capacity() << endl;
    a.reserve(5);
    cout << "a's cap is: " << a.capacity() << endl;
    
    
    return 0;
}