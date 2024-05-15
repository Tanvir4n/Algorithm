// not solved yet
#include <bits/stdc++.h>
#include <iomanip> // for setprecision

using namespace std;

int main(){
    
    int N,W;
    cin>>N>>W;

    vector<int> value(N + 1);
    vector<int> weight(N + 1);

    for(int i=1; i<=N; i++){
        cin>>value[i]>>weight[i];
    }

    // DP array to store maximum value achievable with given weight limit
    vector<double> dp(W + 1, 0);

    // Fill DP table
    for(int i=1; i<=N; i++){
        for(int j=W; j>=weight[i]; j--){
            dp[j] = max(dp[j], dp[j - weight[i]] + value[i]);
        }
    }

    cout<<fixed<<setprecision(8)<<dp[W]<<endl;

    return 0;
}

// https://vjudge.net/problem/Aizu-ALDS1_15_B
