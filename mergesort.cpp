#include <iostream>
using namespace std;

void printarray(int *arr,int e){
    for (int i=0;i<e;i++)
    {
        cout << arr[i]<< " ";
    }
} 
void mergeSortedArrays(int arr[], int s , int e) {
    int mid=s+(e-s)/2;
    int len1=mid-s+1;
    int len2=e-mid;

    int *first = new int[len1];
    int *second = new int [len2];


   int mainarrayindex=s;
   for (int i=0;i < len1;i++)
   {
    first[i]=arr[mainarrayindex++];
   }

   mainarrayindex=mid+1;
   for (int i=0;i < len2;i++)
   {
    second[i]=arr[mainarrayindex++];
   }


    int index1=0;
    int index2=0;
    mainarrayindex=s;
    while (index1 <len1 && index2 < len2) {
        if (first[index1] < second[index2]) {
            arr[mainarrayindex++] = first[index1++];
        } else {
            arr[mainarrayindex++] = second[index2++];
        }
    }

    while (index1 < len1) {
        arr[mainarrayindex++] = first[index1++];
    }

    while (index2 < len2) {
        arr[mainarrayindex++] = second[index2++];
    }
}


void mergesort(int *arr,int s,int e)
{
    if(s>=e)
    {
        return;
    }
    int mid=s+(e-s)/2;
    mergesort(arr,s,mid);
    mergesort(arr,mid+1,e);
    //to merge to sorted array
    mergeSortedArrays(arr,s,e);

}
int main ()
{
    int arr[]={11,12,14,10,9,8,7,4,2,18,11,15};
    int size=sizeof(arr)/sizeof(arr[0]);
    mergesort(arr,0,size-1);
    printarray(arr,size);
}