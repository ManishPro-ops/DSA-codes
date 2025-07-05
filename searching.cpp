#include <iostream>
using namespace std;

void printarray(int *arr,int start,int end){
    for(int i=start;i<end;i++){
        cout << arr[i]<<" ";
    }
}

bool linearsearch(int *arr,int size ,int key)
{
    if (size==0){ 
        return 0 ;
    }
    if (arr[0]==key){
        return 1;
    }
    else{
        return linearsearch(arr+1,size-1,key);
    }
}

bool binarysearch(int *arr,int s,int e,int key)
{
    cout << endl ;
    printarray(arr,s,e);
    int m=s+(e-s)/2;
    if (s>e){
      return 0;
    }
    if (arr[m]==key){
      return 1;
    }
    if (arr[m]> key)
    {
      return binarysearch(arr,s,m-1,key) ;  
    }
    else
    {
      return binarysearch(arr,m+1,e,key) ;
    }
}
int main (){
    int arr[8]={2,5,4,9,10,11,15,18};
    // int size=6;
    int key=16;
    int start=0;
    int end= 8;
    cout << endl;
    // int x=linearsearch(arr,size,key);
    int x=binarysearch(arr,start,end,key);
    if(x==1){
        cout << "element found ";
    }
    else {
        cout << "element not found";
    }
}