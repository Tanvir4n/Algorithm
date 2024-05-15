// 3rd tc wa
#include <bits/stdc++.h>

using namespace std;

int maxWaysToPay(int N, int K, const vector<int>& coins){
    vector<int> dp(K + 1, 0);
    dp[0] = 1;  // Base case: 1 way to make amount 0 (using no coins)

    for(int coin : coins){
        for (int amount=coin; amount<=K; amount++){
            dp[amount] += dp[amount - coin];
        }
    }

    return dp[K];
}

int main(){
    int t;
    cin>>t;  

    vector<int> results;
    while(t--){
        int N,K;
        cin>>N>>K;

        vector<int> coins(N);
        for(int i=0; i<N; i++){
            cin>>coins[i];
        }

        
        int maxWays = maxWaysToPay(N, K, coins);
        results.push_back(maxWays);
    }

    // ***Output results for each test case
    for(int result : results){
        cout<<result<<"\n";
    }

    return 0;
}
---------------------------------------------------
#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

// Function to count the number of ways to make the amount using given coins
int countWays(vector<int>& coins, int amount){
    vector<int> dp(amount + 1, 0);
    dp[0] = 1; // Base case: 1 way to make amount 0 (by choosing nothing)

    for(int coin : coins){
        for(int j=coin; j<=amount; j++){
            dp[j] += dp[j - coin];
        }
    }
    return dp[amount];
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, K;
        cin>>N>>K;

        vector<int> coins(N);
        for (int i=0; i<N; i++){
            cin>>coins[i];
        }
        // Count how many ways we can pay exactly K taka using given coins
        int ways = countWays(coins, K);
        cout<<ways<<endl;
    }

    return 0;
}
