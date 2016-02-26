#include <fstream>
#include <iostream>
#include <cstdlib>
#include <math.h>
#include <stdio.h>

using namespace std;
const int row = 6;
const int column = 8;

void compute(double v[][column])
{
    for(int i=1; i<row-1; ++i){
        for(int j=1; j<column-1; ++j){
            v[i][j] = (v[i-1][j] + v[i][j-1] + v[i][j+1] + v[i+1][j])/4;
        }
    }
}

double difference(double v[][column], double a[][column])
{
    double max = v[1][1] - a[1][1];
    for(int i=1; i<row-1; ++i){
        for(int j=1; j<column-1; ++j){
            a[i][j] = fabs(v[i][j] - a[i][j]);
            if(max < a[i][j])
                max = a[i][j];
        }
    }
    return max;
}

int main()
{
    string inputName, outputName;
    cout << "Enter name of input file: ";
    cin >> inputName;
    cout << "Enter name of output file: ";
    cin >> outputName;
    
    ifstream fin;
    fin.open(inputName.c_str());
    ofstream fout(outputName.c_str());
    if (!fin.is_open())
    {
        cout << "Error opening " << inputName << endl;
        return 0;
    }
    if (!fout.is_open())
    {
        cout << "Error opening " << outputName << endl;
        exit(0);
    }
    
    double n;
    double v[row][column] = {0.0};
    double q[5] = {0};
    int i = 0;
    while (fin >> n)
    {
       q[i] = n;
       ++i;
    }
    
    for(int i=0; i<column; ++i){
        v[0][i] = q[0];
    }
    cout << endl;
    
    for(int j=1; j<row-1; ++j){
        v[j][0] = q[3];
    }
    cout << endl;
    
    for(int k=1; k<row-1; ++k){
        v[k][column-1] = q[1];
    }
    for(int f=0; f<column; ++f){
        v[row-1][f] = q[2];
    }
    
    double a[row][column];
    for(int i=1; i<row-1; ++i){
        for(int j=1; j<column-1; ++j){
            a[i][j] = v[i][j];
        }
    }
    compute(v);
    while(difference(v, a) > q[4])
    {
        for(int i=1; i<row-1; ++i){
            for(int j=1; j<column-1; ++j){
                a[i][j] = v[i][j];
            }
        }
        compute(v);
    }
    
    for(int i=0; i<row; ++i){
        for(int j=0; j<column; ++j){
            fout << v[i][j] << " ";
        }
        fout << endl;
    }
    
    fin.close();
    fout.close();
    
    return 0;
}