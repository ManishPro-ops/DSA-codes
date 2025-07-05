#include <iostream>
#include <vector>

using namespace std;

void transpose(vector<vector<int>>& matrix) {
    int n = matrix.size();
    for (int i = 0; i < n; ++i) {
        for (int j = i; j < n; ++j) {
            swap(matrix[i][j], matrix[j][i]);
        }
    }
}


void reverseRows(vector<vector<int>>& matrix) {
    int n = matrix.size();
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n / 2; ++j) {
            swap(matrix[i][j], matrix[i][n - j - 1]);
        }
    }
}

void rotate90(vector<vector<int>>& matrix) {
    transpose(matrix);
    reverseRows(matrix);
}

void displayMatrix(const vector<vector<int>>& matrix) {
    for (const auto& row : matrix) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
}

int main() {
    vector<vector<int>> matrix = {{1, 2, 3},{4, 5, 6},{7, 8, 9}};

    cout << "Original Matrix:" << endl;
    displayMatrix(matrix);

    rotate90(matrix);

    cout << "\nMatrix after 90-degree rotation:" << endl;
    displayMatrix(matrix);

    return 0;
}
