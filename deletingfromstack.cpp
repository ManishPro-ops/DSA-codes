#include <iostream>
#include <stack>
using namespace std;

// Function to delete the bottom element from the stack
void deletebottom(int count, stack<int> &s, int size) {
    if (count == size) {
        s.pop();  // Pop the bottom element when count reaches size
        return;
    }
    
    int top = s.top();
    s.pop();  // Pop the top element temporarily
    
    deletebottom(count + 1, s, size);  // Recursively go down the stack
    
    s.push(top);  // Push the top element back after recursion
}

void insertatbottom(int count,stack<int> &s, int size,int num){
    if(s.empty()){
        s.push(num);
        return;
    }
    int top=s.top();
    s.pop();
    insertatbottom(count+1,s,size,num);
    s.push(top);
}

int main() {
    stack<int> s;  // Declare a stack of integers
    
    // Push elements onto the stack
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);

    int count = 0;  // Initialize count to 0

    // Call the function to delete the bottom element
    deletebottom(count, s, s.size());

    // Pop and display remaining elements in the stack to verify
    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();  // Pop the top element
    }
    cout << endl;

    return 0;
}
