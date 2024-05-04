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

const int MOD = 100000007;

void Fast(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int longestIncreasingSubsequenceLength(vector<int>& weights){
    
    int n = weights.size();
    if (n == 0)
        return 0;

    // dp[i] will hold the length of the LIS ending at index i
    vector<int> dp(n, 1);

    // Compute the LIS values
    for(int i=1; i<n; i++){
        for(int j=0; j<i; j++){
            if(weights[j] < weights[i]){
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }

    // Find the maximum LIS length from dp array
    int lis_length = 0;
    for (int i=0; i<n; i++){
        lis_length = max(lis_length, dp[i]);
    }

    return lis_length;
}

signed main(){

    Fast();

    int N;
    cin>>N;

    vector<int>weights(N);
    for(int i=0; i<N; i++){
        cin>>weights[i];
    }
    
    int lis_length = longestIncreasingSubsequenceLength(weights);
    cout<<lis_length<<endl;

    return 0;
}
