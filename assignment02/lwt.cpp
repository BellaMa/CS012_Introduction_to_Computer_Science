#include<iostream>
#include<fstream>
#include <math.h>
using namespace std;
const int Row = 6;
const int Col = 8;
void equitemp(float arr[Row][Col],float equi)
{
    float max = 0;
    //float min = 0;
    float arrn [Row][Col]={0};
    int k = 0;
   
    do
    {   
        for(int i=0;i<Row;++i)
        {
            for(int j=0;j<Col;++j)
            {
                arrn[i][j]=arr[i][j];
            }
        }
        for(int i=1;i<Row-1;++i)
        {
            for(int j=1;j<Col-1;++j)
            {
                arr[i][j]=(arr[i-1][j]+arr[i][j+1]+arr[i+1][j]+arr[i][j-1])/4;
            }
        }
        max = fabs(arr[1][1]-arrn[1][1]);
        for(int i= 0;i<Row-1;++i)
        {
            for(int j=1;j<Col-1;++j)
            {
                if(max<fabs(arr[i][j]-arrn[i][j]))
                {
                    max = fabs(arr[i][j]-arrn[i][j]);
                    cout << k++ <<" max = " << max << endl;
                }           
            }
        }
    }while(max>equi);   
    cout << endl << "max = " << max << endl; 
}
int main()
{
    ifstream inFS;
    ofstream outFS;
    string input;
    string output;
    float arr[Row][Col] = {0};
    float equi = 0;
    cout<<"Enter the file name:";
    cin>>input;
    inFS.open(input.c_str());
    if(!inFS.is_open())
    {
       cout<<"File is not open";
       return 1;
    }
    
    inFS>>arr[0][0];
    inFS>>arr[1][Col-1];
    inFS>>arr[Row-1][0];
    inFS>>arr[1][0];
    inFS>>equi;
   // cout<<equi<<" "<<arr[Row-1][0]<<" "<<arr[1][Col-1]<<arr[0][0]<<endl;
    
    
    for(int i=0;i<Col;++i)
    {
        arr[0][i] = arr[0][0];
    }
    
    
    for(int i=1;i<Row-1;++i)
    {
        arr[i][Col-1] = arr [1][Col-1];
    }
    
    for(int i=0;i<Col;++i)
    {
        arr[Row-1][i] = arr [Row-1][0];
        
    }
    for(int i=1;i<Row-1;++i)
    {
        arr[i][0] = arr [1][0];
    }
    equitemp(arr,equi);
    cout<<"Enter the output file name:";
    cin>>output;
    outFS.open(output.c_str());
    outFS.clear();
    //for (int i=1;i<Row-1;++i)
    //    for(int j=1;j<Col-1;++j)
    //    {
    //        
    //        outFS<<arr[i][j]<<" ";
    //        if(j==Col-2)
    //        {
    //            outFS<<endl;
    //        }
    //       
    //    } 
    
    for(int i = 0; i < Row ; ++i){
    
        for(int j = 0; j <Col ; ++j)
            outFS << arr[i][j] << " ";   
        
        outFS << endl;
        
    }
        
        
    
    inFS.close();
    outFS.close();
    return 0;
    
    
}