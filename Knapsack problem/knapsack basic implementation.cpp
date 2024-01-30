#include<bits/stdc++.h>

using namespace std;

int knapsack(int capacity, const vector<int>& weights, const vector<int>& values, int n){
    vector<vector<int>> dp(n + 1, vector<int>(capacity + 1, 0));

    for(int i=1; i<=n; i++){
        for(int w=0; w<=capacity; w++){
            if(weights[i - 1] <= w){
                dp[i][w] = max(values[i - 1] + dp[i - 1][w - weights[i - 1]], dp[i - 1][w]);
            }
            else{
                dp[i][w] = dp[i - 1][w];
            }
        }
    }
    return dp[n][capacity];
}

int main(){
  
    vector<int> weights = {2, 3, 4, 5};
    vector<int> values = {3, 4, 5, 6};
    int capacity = 5;
    int n = weights.size();

    int result = knapsack(capacity, weights, values, n);

    cout<<"Maximum value in the knapsack: "<<result<<endl;

    return 0;
}
