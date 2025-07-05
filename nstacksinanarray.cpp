#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class NStack {
    int* arr;      // Array to store stack elements
    int* top;      // Array to store the index of the top element of each stack
    int* next;     // Array to manage free spaces and links between elements
    int free;      // The beginning index of the next free slot in arr[]
    int n, size;

public:
    // Constructor to initialize n stacks in a single array of given size
    NStack(int numStacks, int totalSize) {
        n = numStacks;
        size = totalSize;
        arr = new int[size];
        top = new int[n];
        next = new int[size];
        free = 0;  // Initially, all slots are free
        
        // Initialize all stack tops as empty (-1)
        for (int i = 0; i < n; i++) {
            top[i] = -1;
        }
        
        // Initialize all spaces in arr[] as free and create a linked list of free slots
        for (int i = 0; i < size - 1; i++) {
            next[i] = i + 1;
        }
        next[size - 1] = -1;  // Mark the end of the free list
    }
    
    // Push x to stack number m-1
    bool push(int x, int m) {
        if (free == -1) {
            cout << "Stack overflow" << endl;
            return false;  // No free space
        }
        
        // Get the index of the next free slot
        int i = free;
        
        // Update the free index to the next available slot
        free = next[i];
        
        // Insert the element in the array
        arr[i] = x;
        
        // Link the new element to the previous top of stack m
        next[i] = top[m - 1];
        
        // Update the top to point to the new top element
        top[m - 1] = i;
        
        return true;
    }
    
    // Pop element from stack number m-1
    int pop(int m) {
        if (top[m - 1] == -1) {
            cout << "Stack underflow" << endl;
            return INT_MIN;  // Stack is empty
        }
        
        // Get the top index of the stack
        int i = top[m - 1];
        
        // Update the top to the next element in the stack
        top[m - 1] = next[i];
        
        // Link the freed slot back to the free list
        next[i] = free;
        free = i;
        
        // Return the popped element
        return arr[i];
    }
    
    // Destructor to free allocated memory
    ~NStack() {
        delete[] arr;
        delete[] top;
        delete[] next;
    }
};

int main() {
    // Example: Create 3 stacks in an array of size 10
    NStack ns(3, 10);
    
    // Push elements to different stacks
    ns.push(15, 1);  // Push 15 to stack 1
    ns.push(45, 2);  // Push 45 to stack 2
    ns.push(17, 1);  // Push 17 to stack 1
    ns.push(49, 2);  // Push 49 to stack 2
    ns.push(39, 3);  // Push 39 to stack 3
    
    // Pop elements from stack 1 and stack 2
    cout << "Popped from stack 1: " << ns.pop(1) << endl;  // 17
    cout << "Popped from stack 2: " << ns.pop(2) << endl;  // 49
    
    return 0;
}
