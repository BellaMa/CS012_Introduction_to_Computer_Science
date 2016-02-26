#include "IntList.h"
#include <iostream>
using namespace std;


IntList::IntList()
: head(0),tail(0)
{ }

IntList::~IntList()
{   
    while(head != 0)
    {   
        pop_front();
    }
}

void IntList::display() const
{   
    if(head == 0)
        return ;
    
    IntNode *tem = 0; 
    for(tem = head; tem->next != 0;tem = tem->next)
    {
        cout <<tem->data << " ";
    }
    cout << tem->data;
}

void IntList::push_front(int value)
{
    IntNode * tem = new IntNode(value);
    tem->next = head;
    head = tem;
    IntNode* cur = head;
    while(cur->next != 0)
        cur = cur->next;
    tail = cur;
}

void IntList::pop_front()
{
    if(head == 0)
        return ;
    
    IntNode *tem = head;
    head = head->next;
    delete tem;
    if(head == 0)
        tail = head;
}


void IntList::push_back(int value)
{
    IntNode* tem = new IntNode(value);
    if(tail == 0)
    {
        tail = tem;
        return ;
    }
    tail->next = tem;
    tail = tem;
}

void IntList::select_sort() //ascending
{
    if(head == 0)
        return ;
        
    int min;
    IntNode * outer = 0;
    IntNode * inner = 0;
   
   for(outer = head; outer->next != 0; outer = outer->next)
   {
       min = outer->data;

       for(inner = outer->next; inner->next != 0; inner = inner->next)
       {
           if(min > inner->data)
           {
               min = inner->data;
               inner->data = outer->data;
               outer->data = min;
           }
       }
       
   }
   
   
   
}



void IntList::insert_sorted(int value)
{
    IntNode * newnode = new IntNode(value);
    
    if(head == 0)        // empty list
    {
        head = newnode;
        tail = newnode;
        return ;
    }
    
    //adding the new value in the list
    //if the new value is the smallest one, add it at the beginning
    if(value < head->data)
    {
        newnode->next = head;
        head = newnode;
        return ;
    }
    //when the new value is bigger than the smallest one, and smaller than the biggest one
    IntNode * loop;
    for(loop = head; loop->next != 0; loop = loop->next)
    {
        if(loop->next->data > value)
        {
            newnode->next = loop->next;
            loop->next = newnode;
            return ;
        }
    }
    
    //when the new value is the biggest one among the whole list, add the new one at the end
    if(tail->data <= value)
    {
        tail->next = newnode;
        tail = newnode;
    }
   
    return ;
}

void IntList::remove_duplicates()
{
    if(head == 0)
    {
        cout << "What the fuck!" << endl;
        return ;
    }
        
        
    
    IntNode * outer = head;
    IntNode * inner = head;
    IntNode * tem = 0;

    int i = 0, j = 0;
    cout << "inside remove_duplicates~" << endl;
    
    
    cout << "i  j:  " << i << " " << j << endl;
    cout << "what the hell!!!" << endl;
}