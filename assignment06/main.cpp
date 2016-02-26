#include "IntList.h"
#include <iostream>
using namespace std;

int main()
{
    IntList intlist;
    cout << "display empty list" << endl;
    intlist.display();
    cout << endl;
    
    for(int i = 1; i < 11; ++i)
    {
        intlist.push_front(i);
    }
    
    cout << "a list from 1 to 10: " << endl;
    intlist.display();
    cout << endl;
    
    for(int i = 0; i < 4; ++i)
    {
        intlist.pop_front();
    }
    intlist.pop_front();
    cout << "pop_front new list: " << endl;
    intlist.display();
    cout << endl;
    
    cout << "push_back new list: " << endl;
    intlist.push_back(22);
    intlist.display();
    cout << endl;
    
    cout <<"select_sort: " << endl;
    intlist.select_sort();
    intlist.display();
    cout << endl;
    
    
    cout <<"insert_sorted: " << endl;
    intlist.insert_sorted(22);
    intlist.display();
    cout << endl;
    
    
    cout <<"remove_duplicates: " << endl;
    intlist.remove_duplicates();
    //intlist.display();
    cout << "here~~~"<<endl;
    
    return 0;
}