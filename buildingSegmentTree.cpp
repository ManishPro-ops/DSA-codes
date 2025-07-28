#include <bits/stdc++.h>
using namespace std;

class SegmentTree {
    
    vector<long long> st;  // segment tree array
    vector<int> arr;       // original array
    int n;                 // size of input array

    void buildTree(int si, int ss, int se) {
        if (ss == se) {
            st[si] = arr[ss];
            return;
        }
        int mid = (ss + se) / 2;
        buildTree(2 * si + 1, ss, mid);
        buildTree(2 * si + 2, mid + 1, se);
        st[si] = st[2 * si + 1] + st[2 * si + 2];
    }

    long long getSumUtil(int si, int ss, int se, int qs, int qe) {
        // no overlap
        if (qs > se || qe < ss) return 0;

        // complete overlap
        if (qs <= ss && se <= qe) return st[si];

        // partial overlap
        int mid = (ss + se) / 2;
        return getSumUtil(2 * si + 1, ss, mid, qs, qe) +
               getSumUtil(2 * si + 2, mid + 1, se, qs, qe);
    }

    void updateUtil(int si, int ss, int se, int index, int newVal) {
        if (ss == se) {
            arr[index] = newVal;
            st[si] = newVal;
            return;
        }
        int mid = (ss + se) / 2;
        if (index <= mid)
            updateUtil(2 * si + 1, ss, mid, index, newVal);
        else
            updateUtil(2 * si + 2, mid + 1, se, index, newVal);

        st[si] = st[2 * si + 1] + st[2 * si + 2];
    }

public:
    SegmentTree(vector<int> &input) {
        arr = input;
        n = input.size();
        st.resize(4 * n, 0);
        buildTree(0, 0, n - 1);
    }

    long long getSum(int l, int r) {
        if (l < 0 || r >= n || l > r) {
            cout << "Invalid Query\n";
            return -1;
        }
        return getSumUtil(0, 0, n - 1, l, r);
    }

    void update(int index, int newVal) {
        if (index < 0 || index >= n) {
            cout << "Invalid Index\n";
            return;
        }
        updateUtil(0, 0, n - 1, index, newVal);
    }

    void printArray() {
        for (auto x : arr) cout << x << " ";
        cout << "\n";
    }
};
// Driver
int main() {
    vector<int> arr = {1, 3, 5, 7, 9, 11};
    SegmentTree seg(arr);

    cout << "Array before: ";
    seg.printArray();

    cout << "Sum of range (1,3): " << seg.getSum(1, 3) << "\n";

    seg.update(1, 10);  // arr[1] = 10

    cout << "Array after: ";
    seg.printArray();

    cout << "Updated sum of range (1,3): " << seg.getSum(1, 3) << "\n";

    return 0;
}