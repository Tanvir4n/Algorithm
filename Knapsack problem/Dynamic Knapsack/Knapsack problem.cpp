// not submitted yet
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Function to solve the knapsack problem and return the maximum value
int knapsack(int n, int B, vector<int>& weights, vector<int>& values){
    // dp[j] will be the maximum value that can be achieved with weight limit j
    vector<int> dp(B + 1, 0);

    for(int i=0; i<n; ++i){
        int curr_weight = weights[i];
        int curr_value = values[i];
        for (int j=B; j>=curr_weight; j--){
            // Update dp[j] by considering whether to take the current item or not
            dp[j] = max(dp[j], dp[j - curr_weight] + curr_value);
        }
    }

    // The answer is the maximum value with weight limit B
    return dp[B];
}

int main(){

    int t;
    cin>>t;

    while(t--){
        int n,B;
        cin>>n>>B;

        vector<int> weights(n);
        vector<int> values(n);

        for(int i=0; i<n; i++){
            cin>>weights[i]>>values[i];
        }

        int max_value = knapsack(n, B, weights, values);
        cout<<max_value<<endl;
    }

    return 0;
}
// https://vjudge.net/problem/FZU-2214

/*
Input
The first line contains the integer T indicating to the number of test cases.
For each test case, the first line contains the integers n and B.
Following n lines provide the information of each item.
The i-th line contains the weight w[i] and the value v[i] of the i-th item respectively.

1 <= number of test cases <= 100
1 <= n <= 500
1 <= B, w[i] <= 1000000000
1 <= v[1]+v[2]+...+v[n] <= 5000
All the inputs are integers.

Output
For each test case, output the maximum value.

Sample Input
1
5 15
12 4
2 2
1 1
4 10
1 2
*/
