#include <iostream>
using namespace std;

class Heap {
public:
    int size;
    int arr[100];

    Heap() {
        arr[0] = -1; // Placeholder for 1-based indexing
        size = 0;
    }

    // Insert a value into the heap
    void insert(int val) {
        size++;
        int index = size;
        arr[index] = val;

        while (index > 1) {
            int parent = index / 2;
            if (arr[parent] < arr[index]) {
                swap(arr[parent], arr[index]);
                index = parent;
            } else {
                return;
            }
        }
    }

    // Delete the root of the heap
    void deletefromheap() {
        if (size == 0) {
            cout << "Nothing to delete" << endl;
            return;
        }

        // Replace root with the last element and reduce size
        arr[1] = arr[size];
        size--;

        // Heapify down
        int i = 1;
        while (i <= size) {
            int leftindex = 2 * i;
            int rightindex = 2 * i + 1;
            int largest = i;

            if (leftindex <= size && arr[leftindex] > arr[largest]) {
                largest = leftindex;
            }
            if (rightindex <= size && arr[rightindex] > arr[largest]) {
                largest = rightindex;
            }
            if (largest != i) {
                swap(arr[i], arr[largest]);
                i = largest;
            } else {
                return;
            }
        }
    }

    // Print the heap
    void print() {
        for (int i = 1; i <= size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

// Heapify a subtree rooted at index `i`
void heapify(int arr[], int size, int i) {
    int largest = i;
    int left = 2 * i;
    int right = 2 * i + 1;

    if (left <= size && arr[left] > arr[largest]) {
        largest = left;
    }
    if (right <= size && arr[right] > arr[largest]) {
        largest = right;
    }
    if (largest != i) {
        swap(arr[largest], arr[i]);
        heapify(arr, size, largest); // Recursive call to heapify the affected subtree
    }
}

int main() {
    Heap h;
    h.insert(50);
    h.insert(40);
    h.insert(20);
    h.insert(70);
    h.insert(77);

    cout << "Heap before deletion: ";
    h.print();

    h.deletefromheap();
    cout << "Heap after deletion: ";
    h.print();

    return 0;
}
