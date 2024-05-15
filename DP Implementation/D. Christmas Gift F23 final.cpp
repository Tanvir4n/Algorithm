#include <iostream>
#include <vector>
using namespace std;

const int MOD = 1000000007;
const int MAX_N = 1000000;

void ISO(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void solution(){
    
    int t;
    cin>>t;
    
    // Precompute dp array
    vector<int> dp(MAX_N + 1, 0);
    
    // Base cases
    if(MAX_N >= 1) dp[1] = 7;
    if(MAX_N >= 2) dp[2] = 13;
    
    // Fill dp array
    for(int i=3; i<=MAX_N; i++){
        dp[i] = (dp[i-1] + dp[i-2] + (9 * (i * i - 3) - 14 * (i - 1))) % MOD;
    }
    
    // Process each test case
    for(int i=0; i<t; i++){
        int n;
        cin>>n;
        cout<<dp[n]<<endl;
    }
    
}
 
signed main(){
 
    ISO();
    solution();
    
 
    return 0;
}
