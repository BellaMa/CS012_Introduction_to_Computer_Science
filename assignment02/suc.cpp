#include <fstream>
#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <math.h>
#include <stdio.h>
using namespace std;


int checkEquilibrium(const double old[6][8],const double metal[6][8],double average){
    for(int i = 1; i < 6; ++i){
        for(int j = 1; j < 7; ++j)
            if(fabs(old[i][j] - metal[i][j]) > average)
                return 1;
    }
    return 0;
}
void tem(double metal[6][8], double old[6][8]){
   
    for(int i = 1; i < 6 - 1; ++i){
        for(int j = 1; j < 8 - 1; ++j){
            old[i][j] = metal[i][j];
            metal[i][j] = (metal[i - 1][j] + metal[i + 1][j] + metal[i][j - 1] + metal[i][j + 1]) / 4;
        }
    }
    
}
int main(){
    
    string inputName, outputName;
    cout << "Enter name of input file: ";
    cin >> inputName;
    cout << "Enter name of output file: ";
    cin >> outputName;
    //inputName = "tem.txt";
    
    
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
    double metal[6][8] = {0}, old[6][8] = {0};
    double side[5] = {0};
    int i = 0;
    while (fin >> n)
    {
        side[i++] = n ;        
    }
    
  
    
    for(int i = 0; i < 8; ++i)
    {
        metal[0][i] = side[0];
        metal[5][i] = side[2];
    }
    
    for(int i = 1; i < 5; ++i){
        metal[i][7] = side[1];
        metal[i][0] = side[3];
    }
    
   
    
    double tolerance = side[4];
    
    while(1){
        tem(metal, old);
        
        if(checkEquilibrium(old, metal, tolerance) == 0)
            break ; 
    }    
    
    for(int i = 1; i < 6 - 1; ++i){
        for(int j = 1; j < 8 - 1; ++j){
            //cout << metal[i][j] << "  ";
            fout << metal[i][j] << " ";
        }
        fout << endl;
    }
    
    
    
    
    fin.close();
    fout.close();
    
    return 0;
}