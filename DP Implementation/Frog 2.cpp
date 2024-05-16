#include <bits/stdc++.h>

using namespace std;

void Fast(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void min_cost(int n, int k, vector<int>& h){
    vector<long long> dp(n + 1, numeric_limits<long long>::max());          // The expression numeric_limits<long long>::max() is a way to obtain the maximum value representable by the int data type in C++.
    dp[1] = 0;

    for(int i=1; i<=n; i++){
        for(int j=1; j<=k; j++){
            if(i + j <= n){
                dp[i + j] = min(dp[i + j], dp[i] + abs(h[i] - h[i + j]));
            }
        }
    }

    cout<<dp[n]<<endl;
}

int32_t main(){
    Fast();

    int n,k;
    cin>>n>>k;

    vector<int> h(n + 1);
    for(int i=1; i<=n; i++){
        cin>>h[i];
    }

    min_cost(n, k, h);

    return 0;
}
