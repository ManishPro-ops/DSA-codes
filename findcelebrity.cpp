#include <iostream>
#include <stack>
#include <vector>
using namespace std;

class Solution {
  
  // Helper function to check if person `a` knows person `b`
  bool knows(vector<vector<int>>& mat, int a, int b, int n) {
      return mat[a][b] == 1;  //if true return true else false;
  }
  
public:
  
    int celebrity(vector<vector<int>>& mat, int n) {
        stack<int> s;
        
        // Push all people (indices) onto the stack
        for (int i = 0; i < n; i++) {
            s.push(i);
        }
        
        // Process the stack until one candidate remains
        while (s.size() > 1) {
            int a = s.top();
            s.pop();
            int b = s.top();
            s.pop();
            
            // Check if `a` knows `b`, if so, `a` cannot be a celebrity
            if (knows(mat, a, b, n)) {
                s.push(b);
            }
            else {
                // `b` cannot be a celebrity, so push `a` back
                s.push(a);
            }
        }
        
        // The remaining candidate is a possible celebrity
        int ans = s.top();
        
        // Verify if the candidate is indeed a celebrity
        int zerocount = 0;
        for (int i = 0; i < n; i++) {
            // Check if the candidate does not know anyone else
            if (mat[ans][i] == 0) {
                zerocount++;
            }
        }
        // The candidate should not know anyone (row must be all 0s except themselves)
        if (zerocount != n) {
            return -1;  // Not a celebrity
        }
        
        // Check if everyone knows the candidate (column should have all 1s except for the candidate themselves)
        int onescount = 0;
        for (int i = 0; i < n; i++) {
            if (mat[i][ans] == 1) {
                onescount++;
            }
        }
        if (onescount != n - 1) {
            return -1;  // Not a celebrity
        }
        
        return ans;  // The candidate is a celebrity
    }
};

int main() {
    Solution sol;
    
    // Test matrix (binary)
    vector<vector<int>> mat = {
        {0, 1, 0, 0},  // Person 0 knows person 1
        {0, 0, 0, 0},  // Person 1 knows no one (potential celebrity)
        {1, 1, 0, 0},  // Person 2 knows person 1, 2
        {1, 1, 1, 0}   // Person 3 knows person 0, 1, and 2
    };
    
    int n = mat.size();  // Size of the matrix (number of people)
    
    // Output the celebrity if found, otherwise indicate no celebrity
    int celeb = sol.celebrity(mat, n);
    if (celeb == -1) {
        cout << "No celebrity found" << endl;
    } else {
        cout << "Celebrity is person " << celeb << endl;
    }
    
    return 0;
}
