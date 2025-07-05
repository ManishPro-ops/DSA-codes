#include <iostream>
using namespace std;
#include<chrono>
using namespace std:: chrono;

void insert_sort(int arr[], int m){
    for (int i=1;i<m;i++)
    {
        int temp=arr[i];
        int j=i-1;
        while(j>=0)
        {
            if (arr[j]>temp)
                arr[j+1]=arr[j];
            else
                break;
            
            j--;
        }
        arr[j+1]=temp;
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
    cout << "Enter size of array: ";
    cin >> m;
    int arr[m];
    for (int i = 0; i < m; i++) {
        arr[i]=m-i;
    }
    auto start=high_resolution_clock::now();
    insert_sort(arr, m);
    auto stop=high_resolution_clock::now();
    auto duration =duration_cast<milliseconds>(stop-start);
    cout << "execution time "<< duration.count()<< "  milliseconds " <<endl;
    //cout << "Sorted array:" << endl;
    // print_array(arr, m);
    return 0;
}
