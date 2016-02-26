
#include "Message.h"
#include <string>
#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

Message::Message()
: author(""), subject(""), body(""),id(0) 
{ }

Message::Message(const string &athr, const string &sbjct, const string &_body,unsigned _id)
: author (athr), subject(sbjct), body(_body), id(_id)
{ }

Message::~Message()
{
}



void Message::print(unsigned indentation) const 
{ 
    string inden = "";
    
    for(int n = indentation; n > 0; --n)
        inden += "  ";
    

    // id = get_id();
    
    if(indentation == 0)
    {
        cout << "Message #" << get_id()     << ": " << subject << endl
             << "from "     << author << ": " << body ;
    }
   
       
    
    
    if(indentation != 0)
    {
        cout << endl;
        
        cout << inden << "Message #" << this->id      << ": " << subject << endl;
        cout << inden << "from "     << this->author  << ": ";
        
        
        stringstream ss(this->body);
        string temp;
        getline(ss, temp);
        cout << temp << endl;
        while(getline(ss, temp))
        {
            cout << inden << temp << endl;
        }
        
            
    }
   
   
    //now print children
        for(unsigned i = 0; i < child_list.size(); ++i)
        {
            child_list.at(i)->print(i + 1);
            
            //cout << "in loop to print child" << endl;
        }
  
}



const string & Message::get_subject() const
{
    return subject;
}

unsigned Message::get_id() const
{
    return id;
}

void Message::add_child(Message *child)
{
    child_list.push_back(child);
}