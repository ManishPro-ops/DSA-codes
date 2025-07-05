#include<iostream>
#include<stack>
#include<vector>
using namespace std;

// Function to find the index of the previous smaller element for each element in the array
vector<int> prevsmallerelement(vector<int>& arr, int n) {
    stack<int> s;
    s.push(-1);  // Initialize stack with -1 (indicating no smaller element found)
    vector<int> ans(n);

    // Iterate through the array
    for (int i = 0; i < n; i++) {
        int curr = arr[i];
        
        // Pop elements from stack until we find a smaller element
        while (s.top() != -1 && arr[s.top()] >= curr) {
            s.pop();
        }
        
        // Store the index of the previous smaller element
        ans[i] = s.top();
        
        // Push the current element's index onto the stack
        s.push(i);
    }
    return ans;
}

// Function to find the index of the next smaller element for each element in the array
vector<int> nextsmallerelement(vector<int>& arr, int n) {
    stack<int> s;
    s.push(-1);  // Initialize stack with -1 (indicating no smaller element found)
    vector<int> ans(n);

    // Iterate through the array from right to left
    for (int i = n - 1; i >= 0; i--) {
        int curr = arr[i];
        
        // Pop elements from stack until we find a smaller element
        while (s.top() != -1 && arr[s.top()] >= curr) {
            s.pop();
        }
        
        // Store the index of the next smaller element
        ans[i] = s.top();
        
        // Push the current element's index onto the stack
        s.push(i);
    }
    return ans;
}

// Function to calculate the largest rectangle area in a histogram
int largestrectanglearea(vector<int>& heights) {
    int n = heights.size();
    
    // Get the indices of the next smaller and previous smaller elements
    vector<int> next = nextsmallerelement(heights, n);
    vector<int> prev = prevsmallerelement(heights, n);

    int area = INT_MIN;  // Initialize the area as the smallest possible value
    
    // Iterate through each bar in the histogram
    for (int i = 0; i < n; i++) {
        int l = heights[i];  // Height of the current bar
        
        // If there's no smaller element to the right, assume it's the last element
        if (next[i] == -1) {
            next[i] = n;
        }
        
        // Calculate the width of the rectangle (distance between next and previous smaller elements)
        int b = next[i] - prev[i] - 1;
        
        // Calculate the area of the rectangle
        int newarea = l * b;
        
        // Update the maximum area found so far
        area = max(area, newarea);
    }
    return area;
}

// Function to calculate the largest rectangle area in a binary matrix
int checklargest(vector<vector<int>>& matrix) {
    int n = matrix.size();  // Number of rows
    int m = matrix[0].size();  // Number of columns
    
    // Calculate the area for the first row as if it's a histogram
    int area = largestrectanglearea(matrix[0]);

    // Iterate through the remaining rows
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < m; j++) {
            // If the current element is non-zero, add the previous row's value
            if (matrix[i][j] != 0) {
                matrix[i][j] += matrix[i - 1][j];
            } else {
                // If it's zero, reset the value to zero
                matrix[i][j] = 0;
            }
        }
        // Calculate the largest rectangle area for the current row (histogram)
        area = max(area, largestrectanglearea(matrix[i]));
    }

    return area;  // Return the maximum area found
}

int main() {
    // Test matrix (binary)
    vector<vector<int>> matrix = {
        {1, 0, 1, 0, 0},
        {1, 0, 1, 1, 1},
        {1, 1, 1, 1, 1},
        {1, 0, 0, 1, 0}
    };

    // Output the largest rectangle area
    cout << "Largest rectangle area is: " << checklargest(matrix) << endl;

    return 0;
}
