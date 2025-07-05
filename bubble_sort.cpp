#include<iostream>
using namespace std;

void bubble_sort(int arr[], int n)
{
     for (int i=0;i<n-1;i++){
        bool swapped =false;
        for (int j=0;j<n-i;j++){
            if(arr[j]>arr[j+1]){
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
                swapped = true;                                   // for optimizing code 
            }           
        }
        if(swapped == false)
        {
            break;
        }
    }
}

void print_array(int arr[], int m) {
    for (int i = 0; i < m; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int m;
    cout << "Enter size of array:  ";
    cin >> m;
    int arr[m];
    for (int i = 0; i < m; i++) {
        cout << "Enter element " << i + 1 << ": ";
        cin >> arr[i];
    }
    bubble_sort(arr, m);
    cout << "Sorted array:" << endl;
    print_array(arr, m);
    return 0;
}
