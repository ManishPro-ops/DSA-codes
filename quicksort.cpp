#include <iostream>
using namespace std;

void printarray(int *arr,int e)
{
    for (int i=0;i<e;i++)
    {
        cout << arr[i]<< " ";
    }
}


int partition(int *arr,int s,int e)
{
    int pivot=arr[e];
    int count=0;
    for(int i=s+1;i<=e;i++)
    {                                   //count elements in array that are smaller than starting element
        if (arr[i]<=pivot)
        {
            count++;
        }
    }

    int pivotIndex= s+count ;            //states the actual position of pivot
    swap(arr[e],arr[pivotIndex]);

    int i=s;
    int j=e;
    while(i< pivotIndex && j> pivotIndex)
    {
        while(arr[i]<pivot){
            i++;
           
        }
        while(arr[j]>pivot){             
            j--;
        }

        if(i<pivotIndex && j>pivotIndex)
        {
            swap(arr[i++],arr[j--]);      //swap the elements of right and left of pivot
           
        }
         

    }
    return pivotIndex;
}

void quicksort(int *arr,int s,int e)
{
    
    if(s>=e)
    {
        return;
    }
    int p=partition(arr,s,e);
    quicksort(arr,s,p-1);
    quicksort(arr,p+1,e);
}

int main ()
{
    int arr[]={11,12,14,10,9,8,7,4,2,18,11,15};
    int size=sizeof(arr)/sizeof(arr[0]);
    cout << " array before sorting " << endl<< endl;
    printarray(arr,size);
    quicksort(arr,0,size-1);
    cout <<endl<< endl<< " array after sorting " << endl<< endl;
    printarray(arr,size);
}