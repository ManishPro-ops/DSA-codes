#include <iostream>
#include <chrono>
#include <algorithm> 
#include <random>
using namespace std::chrono;
using namespace std;

int LinearSearch(int arr[], int n, int element) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == element) {
            return i;
        }
    }
    return -1;
}

void analyzeLinearSearch(int n, int trials = 5) {
    int *arr = new int[n];
    double best = 0, worst = 0, average = 0;

    for (int t = 0; t < trials; t++) {
        // Best case
        for (int i = 0; i < n; i++) {
            arr[i] = i;
        }
        auto start = high_resolution_clock::now();
        LinearSearch(arr, n, 0);
        auto stop = high_resolution_clock::now();
        best += duration_cast<microseconds>(stop - start).count();

        // Worst case
        start = high_resolution_clock::now();
        LinearSearch(arr, n, n - 1);
        stop = high_resolution_clock::now();
        worst += duration_cast<microseconds>(stop - start).count();

        // Average case
        double avg_trial = 0;
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> dis(0, n - 1);

        for (int i = 0; i < n; i++) {
            arr[i] = i;
        }
        
        for (int i = 0; i < n; i++) {
            int random_element = arr[dis(gen)];
            start = high_resolution_clock::now();
            LinearSearch(arr, n, random_element);
            stop = high_resolution_clock::now();
            avg_trial += duration_cast<microseconds>(stop - start).count();
        }
        average += avg_trial / n;
    }

    cout << "For size " << n << ":\n\n";
    cout << "Average Best Case Duration: " << best / trials << " microseconds\n";
    cout << "Average Worst Case Duration: " << worst / trials << " microseconds\n";
    cout << "Average Average Case Duration: " << average / trials << " microseconds\n\n";

    delete[] arr;
}

int main() {
    analyzeLinearSearch(1000);
    analyzeLinearSearch(10000);
    analyzeLinearSearch(100000);
    return 0;
}