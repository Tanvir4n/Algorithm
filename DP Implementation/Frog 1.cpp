#include <bits/stdc++.h>

using namespace std;

void Fast(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void min_cost(){
    int n;
    cin>>n;

    vector<int> h(n + 1);
    for(int i=1; i<=n; i++){
        cin>>h[i];
    }

    vector<int> dp(n + 1, numeric_limits<int>::max());              // The expression numeric_limits<int>::max() is a way to obtain the maximum value representable by the int data type in C++.
    dp[1] = 0;

    for(int i=1; i<=n; i++){
        if(i+1 <= n){
            dp[i + 1] = min(dp[i + 1], dp[i] + abs(h[i] - h[i + 1]));
        }
        if(i+2 <= n){
            dp[i + 2] = min(dp[i + 2], dp[i] + abs(h[i] - h[i + 2]));
        }
    }

    cout<<dp[n]<< endl;

}

int32_t main(){

    Fast();
    min_cost();

    return 0;
}
