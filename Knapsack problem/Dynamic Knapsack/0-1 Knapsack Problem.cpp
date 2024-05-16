#include <bits/stdC++.h>

using namespace std;

int knapsack(int n, int w, vector<pair<int, int>>& items){
    
    vector<int> dp(w + 1, 0);                               // Create a dp array to store maximum values

    for(int i=0; i<n; i++){                                 // Process each item
        int value = items[i].first;
        int weight = items[i].second;

        for(int j=w; j>=weight; j--){                       // Traverse the dp array from right to left
            dp[j] = max(dp[j], dp[j - weight] + value);     // Update dp[w] if including the current item yields a better value
        }
    }

    return dp[w];
}

int main(){
    int n, w;
    cin>>n>>w;

    vector<pair<int, int>> items(n);

    for(int i=0; i<n; i++){
        cin>>items[i].first>>items[i].second;
    }

    int max_value = knapsack(n, w, items);

    cout<<max_value<<endl;

    return 0;
}
// https://vjudge.net/problem/Aizu-DPL_1_B
