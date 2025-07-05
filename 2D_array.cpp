#include<iostream>
using namespace std;


void rowSum(int arr[][4],int row,int col)
{
    for (int i=0; i<row; i++)
    {
        int sum=0;
        for (int j=0; j<col; j++){                     // rowwise sum
            sum+=arr[i][j];
        }
        cout << sum << " ";
    }
}

int rowMaxSum(int arr[][4],int row,int col)
{
    int maxsum=INT_MIN;
    int index = -1;
    for (int i=0; i<row; i++)
    {
        int sum=0;
        for (int j=0; j<col; j++)
        {                     
            sum+=arr[i][j];
            
        }
        if (maxsum<sum)
        {
            maxsum=sum;
            index = i+1;
        }
    }
    cout << index << endl;
    return maxsum;

}



void takeinput(int arr[][4],int row,int col){
    int count =1;
    for (int i=0; i<row; i++)
    {
        for (int j=0; j<col; j++){
            cout << "enter element "<<  count << "  ";
            cin  >> arr[i][j];
            count ++;
        }
    }
}
void giveoutput(int arr[][4],int row,int col){
    for (int i=0; i<row; i++)
    {
        for (int j=0; j<col; j++){
            cout << arr[i][j] << "  ";
        }
        cout << endl;
    }
}
int main(){
    // int row,col;
    // cout<< "enter no of rows" << endl;
    // cin >> row;                              //problem
    // cout<< "enter no of cols" << endl;
    // cin >> col;
    int arr1[3][4];
    takeinput(arr1,3,4);
    giveoutput(arr1,3,4);
    rowSum(arr1,3,4);
    cout << endl << rowMaxSum(arr1,3,4);
}