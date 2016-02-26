#include <stdio.h>
#include <iostream>
#include <math.h>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

using namespace std;


double randFloat (double a, double b)
{
   return a + (static_cast<double>(rand()) / RAND_MAX) * (b - a);
}


double rand_mv(double mean, double var);

int main(){
    
    
    double mean, var;
    cout << "Enter mean: x.xx\n";
    cin >> mean;
    cout <<"Enter var: x.xx\n";
    cin >> var;
    
    srand(333);

    rand_mv(mean, var);
  
    return 0;
}


double rand_mv(double mean, double var){
    double a,b;
    
    a = mean + sqrt(3) * sqrt(var);
    b = mean - sqrt(3) * sqrt(var);
    
    cout << a << " " << b << endl;
    
    return randFloat(a,b);
}