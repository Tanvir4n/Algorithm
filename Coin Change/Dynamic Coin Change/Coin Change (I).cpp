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

void ISO(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int coinChangeWays(int n, int k, vector<int>& A, vector<int>& C){
    // Initialize a 2D vector DP array
    vector<vector<int>> dp(k + 1, vector<int>(n + 1, 0));
    dp[0][0] = 1; // Base case: 1 way to make amount 0 (using no coins)

    // Iterate over each coin type
    for(int i=1; i<=n; i++){
        int coinValue = A[i - 1];
        int coinCount = C[i - 1];

        // Update the DP table for the current coin type
        for(int j=0; j<=k; j++){
            dp[j][i] = dp[j][i - 1]; // Ways without using current coin

            // Use up to coinCount of the current coinValue
            for(int l=1; l<=coinCount && j >= l * coinValue; l++){
                dp[j][i] = (dp[j][i] + dp[j - l * coinValue][i - 1]) % MOD;
            }
        }
    }

    return dp[k][n];    // The result is stored in dp[K][n]
}

signed main(){

    ISO();

    int t;
    cin>>t;

    for(int i=1; i<=t; i++){
        int n,k;
        cin>>n>>k;

        vector<int> A(n), C(n);
        for(int j=0; j<n; j++){
            cin>>A[j];
        }
        for(int j=0; j<n; j++){
            cin>>C[j];
        }

        // Calculate the number of ways to make amount K using the coins
        int ways = coinChangeWays(n, k, A, C);

        // Output the result for this test case
        cout<<"Case "<<i<<": "<<ways<<endl;
    }

    return 0;
}
