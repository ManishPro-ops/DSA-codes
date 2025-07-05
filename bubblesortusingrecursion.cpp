#include <iostream>
using namespace std;

void bubblesort(int *arr,int size){
    if(size==0||size==1)
    {
        return;
    }
    //take largest value to right most value
    for (int i=0;i<size-1;i++)
    {
        if(arr[i]>arr[i+1])
        {
            swap(arr[i],arr[i+1]);
        }
    }
    
    bubblesort(arr,size-1);
}
int main()
{
    int arr[5]={10,9,8,7,6};
    int n=5;
    bubblesort(arr,n);
    for(int i=0;i<n;i++){
        cout << arr[i]<< " ";
    }
}