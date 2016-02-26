#include "Message.h"
#include <string>
#include <iostream>
using namespace std;

Message::Message()
: author(""), subject(""), body("") 
{ }

Message::Message(const string &athr, const string &sbjct, const string &body)
: author (athr), subject ( sbjct)
{
    this->body = body;
}

//displays the message in the given format. See output specs.
//Note: R’Sub will require an endl as the last output of this
//function.
void Message::display() const
{
    if(author == "")
    {
        cout << "Nothing to Display.";
    }
    else
    {
        cout << subject << endl;
        cout << "from " << author << ": " << body << endl;
    }
}