#include <iostream>
using namespace std;

int getSum(int *arr,int size)
{
    if (size ==0 ){
        return 0;
    }
    if (size ==1 ){
        return arr[0];
    }
    int sum  = arr[0]+getSum(arr+1,size-1); 
    return sum; 
} 
bool sorted(int *arr,int size){
    if (size ==0 || size == 1){
        return true;
    }
    if (arr[0]>arr[1])
    {
        return false;
    }
    bool remaining_part=sorted(arr+1,size-1); 
    return remaining_part; 
} 
int main(){
    int arr[5]={1,2,3,4,5};
    cout << getSum(arr,5);
    // int z=sorted(arr,5);
    // if (z==1){
    //     cout<<"array is sorted";
    // }                                /*sorted or not*/
    // else{
    // cout<<"array is not sorted";
    // }
}