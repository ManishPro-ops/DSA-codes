#include <iostream>
using namespace std;
#include<chrono>
using namespace std:: chrono;

void selectsort(int arr[], int m) {
    for (int i = 0; i < (m - 1); i++) {
        int min_index = i;
        for (int j = i + 1; j < m; j++) {
            if (arr[j] < arr[min_index]) {
                min_index = j;
            }
        }
        if (min_index != i) {
            swap(arr[i],arr[min_index]);
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
    cout << "Enter size of array: ";
    cin >> m;
    int arr[m];
    for (int i = 0; i < m; i++) {
        cout << "Enter element " << i + 1 << ": ";
        cin >> arr[i];
    }
    auto start=high_resolution_clock::now();
    selectsort(arr, m);
    auto stop=high_resolution_clock::now();
    auto duration =duration_cast<milliseconds>(stop-start);
    cout << "execution time "<< duration.count()<< "  milliseconds " <<endl;
    cout << "Sorted array:" << endl;
    print_array(arr, m);
    return 0;
}
