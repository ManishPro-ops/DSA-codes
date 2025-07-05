#include<iostream>
using namespace std;

void wave_(int arr[][4],int row,int col)
{
    for (int i=0;i<row;i++)
    {
       if (i%2==0)
       {
            for (int j=0;j<col;j++)
            {
                cout << arr[i][j]<< "  ";
            }
            cout << endl;
       }
       else
       {
            for (int j=col-1;j>-1;j--)
            {
            cout << arr[i][j]<< "  ";
            }
            cout << endl;
       }
    }
}


void spiral(int arr[][4],int row,int col)
{
    int count =0;
    int total = row*col;
    int startingrow=1;
    int endingrow= row-1;
    int startingcol=0;
    int endingcol=col-1;
    int i=0;
    int j=0;

    while(total>= count ){
        while(total>= count && j<endingcol){ 
            cout << arr[i][j] << " ";
            count++;
            j++;
        }
        endingcol--;

        while(total>= count && i<endingrow){
            cout << arr[i][j] << " ";
            count++;
            i++;
        }

        endingrow--;

        while(total>= count && j>startingcol){
            cout << arr[i][j] << " ";
            count++;
            j--;
        }

        startingcol++;

        while(total>= count && i>startingrow){
            cout<< arr[i][j] << " ";
            count++;
            i--;
        }
        startingrow++;
    }

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
int main()
{
    int arr1[3][4];
    takeinput(arr1,3,4);
    spiral(arr1,3,4);
    
}