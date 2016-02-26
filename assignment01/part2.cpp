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

//compute the theoretical mean
double theoretical_mean (double a, double b);
//compute the pratical mean
double pratical_mean (const double ra[], int n);
//compute the theoratical variance
double theoratical_variance (double a, double b);
//compute pratical variance
double pratical_variance (const double ra[], int n);

int main(){
    double a2 = 1.5505, a1 = 2.77526;
    double b2 = 6.4495, b1 = 5.22474;
    srand(333);
    double rand1[500], rand2[500];
    
    for (int i = 0; i < 500; ++i){
        rand1[i] = randFloat(a1,b1);
    }
    
    for (int j = 0; j < 500; ++j){
        rand2[j] = randFloat(a2,b2);
    }
    
    //compute the theoretical mean
    double th_mean_1 = theoretical_mean(a1,b1);
    //compute the pratical mean
    double pr_mean_1 = pratical_mean(rand1, 500);
    //compute the theoratical variance
    double th_va_1 = theoratical_variance(a1,b1);
    //compute pratical variance
    double pr_va_1 = pratical_variance(rand1, 500);
    
    //compute the theoretical mean
    double th_mean_2 = theoretical_mean(a2,b2);
    //compute the pratical mean
    double pr_mean_2 = pratical_mean(rand2, 500);
    //compute the theoratical variance
    double th_va_2 = theoratical_variance(a2,b2);
    //compute pratical variance
    double pr_va_2 = pratical_variance(rand2, 500);

    cout << th_mean_1 << " " << pr_mean_1 << " " << th_va_1 << " " << pr_va_1 << endl;
    cout << th_mean_2 << " " << pr_mean_2 << " " << th_va_2 << " " << pr_va_2 << endl;
    
    
}



//compute the theoretical mean
double theoretical_mean (double a, double b){
    return (double) (a + b)/2;
}
//compute the pratical mean
double pratical_mean (const double ra[], int n){
    int i;
    double sum = 0;
    for (i = 0; i < n; ++i){
        sum = sum + ra[i];
    }
    
    double mean = sum / n;
    return mean;
}
//compute the theoratical variance
double theoratical_variance (double a, double b){
    double variance = pow((b - a), 2) / 12;
    return variance;
}
//compute pratical variance
double pratical_variance (const double ra[], int n){
    int i = 0;
    double mean = pratical_mean(ra, n);
    double sum = 0, k;
    for (i=0; i < n; ++i){
        k = ra[i] - mean;
        sum = sum + k * k;
    }
    double variance = sum / n;
    return variance;
}
