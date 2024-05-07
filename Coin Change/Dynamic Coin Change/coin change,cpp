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

void ISO(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int countWays(int n, const vector<int>& coins){

    vector<int> dp(n+1, 0);
    dp[0]=1;

    for(int coin : coins){
        for(int j=coin; j<=n; j++){
            dp[j] = (dp[j] + dp[j - coin]);
        }
        
    }

    return dp[n];
}
 
signed main(){
 
    ISO();
   
    int n;
    cin>>n;

    vector<int>coins={50, 25, 10, 5, 1};

    int ways = countWays(n, coins);

    cout<<ways<<nl;

    return 0;
}

/ https://vjudge.net/problem/HDU-2069
