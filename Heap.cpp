#include <iostream>
#include <vector>
using namespace std;

class Heap {
public:
    vector<int> arr; // 1-based indexing

    Heap() {
        arr.push_back(-1); // placeholder for index 0
    }

    // Insert into heap
    void insert(int val) {
        arr.push_back(val);
        int index = arr.size() - 1;

        while (index > 1 && arr[index / 2] < arr[index]) {
            swap(arr[index / 2], arr[index]);
            index = index / 2;
        }
    }

    // Delete root
    void deleteFromHeap() {
        int size = arr.size() - 1;
        if (size == 0) {
            cout << "Nothing to delete\n";
            return;
        }

        // Move last element to root
        arr[1] = arr[size];
        arr.pop_back();
        size--;

        int i = 1;
        while (true) {
            int left = 2 * i;
            int right = 2 * i + 1;
            int largest = i;

            if (left <= size && arr[left] > arr[largest])
                largest = left;
            if (right <= size && arr[right] > arr[largest])
                largest = right;

            if (largest != i) {
                swap(arr[i], arr[largest]);
                i = largest;
            } else
                break;
        }
    }

    void print() {
        for (int i = 1; i < arr.size(); i++)
            cout << arr[i] << " ";
        cout << "\n";
    }
};

// Heapify for building heap from array
void heapify(vector<int> &arr, int n, int i) {
    int largest = i;
    int left = 2 * i;
    int right = 2 * i + 1;

    if (left <= n && arr[left] > arr[largest]) largest = left;
    if (right <= n && arr[right] > arr[largest]) largest = right;

    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

// Build heap from array
void buildHeap(vector<int> &arr) {
    int n = arr.size() - 1; // 1-based indexing
    for (int i = n / 2; i > 0; i--)
        heapify(arr, n, i);
}

int main() {
    Heap h;
    h.insert(50);
    h.insert(40);
    h.insert(20);
    h.insert(70);
    h.insert(77);
    h.insert(30);
    h.insert(20);
    h.insert(10);
    h.insert(5);


    cout << "Heap before deletion: ";
    h.print();

    h.deleteFromHeap();
    cout << "Heap after deletion: ";
    h.print();
    h.insert(80);
    h.print();

    // Example: building heap from an existing array
    vector<int> arr = {-1, 10, 30, 20, 5, 50}; // 1-based indexing
    buildHeap(arr);
    cout << "Heap built from array: ";
    for (int i = 1; i < arr.size(); i++)
        cout << arr[i] << " ";
    cout << "\n";

    return 0;
}
