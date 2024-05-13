#include <bits/stdc++.h>

using namespace std;

#define int long long
#define ll long long
#define ull unsigned long long
#define ui unsigned int
#define pi acos(-1)
#define pb push_back
#define endl "\n"
#define nl "\n"

void Fast(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void knapsack(int n, int k, vector<int>& weight, vector<int>& values){

    vector<int> dp(k+1, 0);
    dp[0] = 0;
    for(int i=0; i<=n; i++){
        for(int j=k; j>=weight[i]; j--){
            dp[j] = max(dp[j], dp[j - weight[i]] + values[i]);
        }
    }
    int max_value = dp[k];
    int totalW = accumulate(weight.begin(), weight.end(), 0);
    //int totalW = 0;

    for(int i=0; i<n; i++){
        totalW += weight[i];
    }

    cout<<max_value<<endl;

}

signed main(){

    Fast();
    // solution();

    int n,k;
    cin>>n>>k;

    vector<int> weight(n);
    for(int i=0; i<n; i++){
        cin>>weight[i];
    }

    vector<int> values(n);
    for(int i=0; i<n; i++){
        cin>>values[i];
    }

    knapsack(n, k, weight, values);

    return 0;
}
