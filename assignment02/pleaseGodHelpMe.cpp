#include <fstream>
#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <math.h>
#include <stdio.h>
using namespace std;

const int ROW = 6;
const int COL = 8;

double checkEquilibrium(const double old[ROW][COL],const double metal[ROW][COL]){
    double max = fabs(old[1][1] - metal[1][1]);
    double current[ROW][COL];
    for(int i = 1; i < ROW - 1; ++i){
        for(int j = 1; j < COL -1; ++j){
            current[i][j] = fabs(metal[i][j] - old[i][j]);
            if(max < current[i][j])
                max = current[i][j];
        }
    }
    
    return max;
}
void tem(double metal[ROW][COL], double old[ROW][COL]){
   for(int i = 0; i < ROW; ++i)
       for(int j = 0; j < COL; ++j)
        old[i][j] = metal[i][j];
   
   
    for(int i = 1; i < ROW - 1; ++i){
        for(int j = 1; j < COL - 1; ++j){
            metal[i][j] = (metal[i - 1][j] + metal[i + 1][j] + metal[i][j - 1] + metal[i][j + 1]) / 4;
            //arr[i][j]=(arr[i-1][j]+arr[i][j+1]+arr[i+1][j]+arr[i][j-1])/4;
            
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
        return 0;
    }
    
    double metal[ROW][COL] = {0}, old[ROW][COL] = {0};
    double side[5] = {0};
    //int i = 0;
    //while (fin >> side[i++]) ;
    fin >> side[0];
    fin >> side[1];
    fin >> side[2];
    fin >> side[3];
    fin >> side[4];
    
  
    
    for(int i = 0; i < COL; ++i)
    {
        metal[0][i] = side[0];
        metal[ROW - 1][i] = side[2];
    }
    
    for(int i = 1; i < ROW - 1; ++i){
        metal[i][COL - 1] = side[1];
        metal[i][0] = side[3];
    }
    
   
    
    double tolerance = side[4];
    
    double max = 9999;
    //int k = 0;
    while(1){
        tem(metal, old);
        max = checkEquilibrium(old, metal);
        //cout<< k++ << " max = " << max <<endl;

        if( max < tolerance)
            break ; 
    }    
    
    for(int i = 1; i < ROW - 1 ; ++i){
        for(int j = 1; j < COL - 1 ; ++j){
            //cout << metal[i][j] << "  ";
            fout << metal[i][j] << " ";
        }
        fout << endl;
    }
    
    
    //cout << endl << "max = " << max <<endl;
    
    fin.close();
    fout.close();
    
    return 0;
}