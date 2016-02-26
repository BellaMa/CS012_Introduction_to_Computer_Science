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
    int a, b;
    cout << "enter a:   ";
    cin >> a;
    cout << "enter b:   ";
    cin >> b;
    srand(333);
    double rand_1000[1000];
    double rand_1000000[1000000];
    
    for (int i = 0; i < 1000; ++i){
        rand_1000[i] = randFloat(a,b);
    }
    
    for (int j = 0; j < 1000000; ++j){
        rand_1000000[j] = randFloat(a,b);
    }
    
    //compute the theoretical mean
    double th_mean_1000 = theoretical_mean(a,b);
    //compute the pratical mean
    double pr_mean_1000 = pratical_mean(rand_1000, 1000);
    //compute the theoratical variance
    double th_va_1000 = theoratical_variance(a,b);
    //compute pratical variance
    double pr_va_1000 = pratical_variance(rand_1000, 1000);
    
    //compute the theoretical mean
    double th_mean_1000000 = theoretical_mean(a,b);
    //compute the pratical mean
    double pr_mean_1000000 = pratical_mean(rand_1000000, 1000000);
    //compute the theoratical variance
    double th_va_1000000 = theoratical_variance(a,b);
    //compute pratical variance
    double pr_va_1000000 = pratical_variance(rand_1000000, 1000000);

    cout << th_mean_1000 << " " << pr_mean_1000 << " " << th_va_1000 << " " << pr_va_1000 << endl;
    cout << th_mean_1000000 << " " << pr_mean_1000000 << " " << th_va_1000000 << " " << pr_va_1000000 << endl;
    
    
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
