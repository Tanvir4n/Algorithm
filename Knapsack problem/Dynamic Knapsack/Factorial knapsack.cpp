#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Function to calculate factorial
int factorial(int n) {
    if (n == 0 || n == 1)
        return 1;
    return n * factorial(n - 1);
}

// Function to solve factorial knapsack problem
int factorialKnapsack(int capacity, vector<int>& weights, vector<int>& values) {
    int n = weights.size();
    vector<vector<int>> dp(n + 1, vector<int>(capacity + 1, 0));

    for (int i = 1; i <= n; ++i) {
        int weight = weights[i - 1];
        int val = values[i - 1];

        for (int w = 0; w <= capacity; ++w) {
            dp[i][w] = dp[i - 1][w]; // Carry over from the previous item

            if (weight <= w) {
                // Include the current item
                int factor = factorial(weight);
                dp[i][w] = max(dp[i][w], dp[i - 1][w - weight] + val * factor);
            }
        }
    }

    return dp[n][capacity];
}

int main() {
    vector<int> weights = {2, 3, 4, 5};
    vector<int> values = {1, 2, 5, 6};
    int capacity = 8;

    int maxValue = factorialKnapsack(capacity, weights, values);
    cout << "Maximum value that can be obtained: " << maxValue << endl;

    return 0;
}
