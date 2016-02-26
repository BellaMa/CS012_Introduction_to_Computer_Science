#include <iostream>
#include <vector>
using namespace std ;

int search (const vector<int> & v ,int num)
{
    int size = v.size();
    int i;
    for (i=0; i < size; i++)
    {
        if (v.at(i) == num)
            return i;
    }
    
    return -1;
}

void remove_an_item (vector<int> & v , int loc)
{
    v.erase(v.begin()+loc);
}


int main(){
    
    vector<int> vec ;
    
    cout << "Please enter in integers (0 to stop): " ;
    int i;
    
    while (1)
    {
        cin >> i;
        if ( i != 0 )
            vec.push_back(i);
        else
            break;
    }
    cout << "What number would you like to find and remove?: ";
    int n;
    cin >> n;
    
    //now we will search a number and print out its index in the vector
    int loc;
    loc = search (vec, n);
    
        cout << "Found: "<< loc;
        
        
        //now we will remove that number from our vector and print out the new vector
        if ( loc != -1)
            remove_an_item(vec, loc);
            
        int len = vec.size();
          
        cout << "\nResult: ";
        for (i=0; i < len; i++)
            cout << vec.at(i) << " ";
            
        cout << endl;
        
    
    return 0;
}

