#include "Message.h"
#include "Topic.h"
#include <string>
#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

Topic::Topic(const string &athr, const string &sbjct, 
             const string & body, unsigned id)
:Message(athr, sbjct, body, id)
{ }

bool Topic::is_reply() const
{
    return false;
}

string Topic::to_formatted_string() const
{ 
    vector<unsigned> id;
    for(unsigned i = 0; i < child_list.size(); ++i)
    {
        id.push_back(child_list.at(i)->get_id());
    }
    
    
    //transfer int to string
    stringstream s_id;
    s_id << this->get_id();
    string str_id;
    str_id = s_id.str();
    stringstream ss;
    for(unsigned i = 0; i < id.size(); ++i)
    {
        ss << id.at(i);
        ss.put(' ');
    }
    string id_stream = "";
    id_stream = ss.str();
    
    string topic_stored = "";
    string begin = "<begin_topic>";
    string id_str = ":id: ";
    string sub = ":subject: ";
    string aut = ":from: ";
    string chi = ":children: ";
    string bod = ":body: ";
    string end = "<end>";
    
    if(id_stream != "")
    {
        topic_stored = begin + '\n' +
                       id_str + str_id + '\n' +
                       sub + subject + '\n' +
                       aut + author + '\n' +
                       chi + id_stream + '\n' +
                       bod + body  + '\n' +
                       end + '\n';
        
    }
    else{
        topic_stored = begin + '\n' +
                       id_str + str_id + '\n' +
                       sub + subject + '\n' +
                       aut + author + '\n' +
                       bod + body  + '\n' +
                       end + '\n';
        
    }
   
    
                   

    return topic_stored;
                   
}



