// coin change minCountWays by hamza
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

int count(int coins[], int n, int sum)
{
    int dp[sum + 1];
    memset(dp, 0, sizeof(dp));
    dp[0] = 1;
    for (int i = 0; i < n; i++)
        for (int j = coins[i]; j <= sum; j++)
            dp[j] += dp[j - coins[i]];
    return dp[sum];
}

void solution(){
  int n, k; cin>>n>>k;
  int coins[n] = {0};
  for(int i = 0; i<n; i++){
    cin>>coins[i];
  }
  cout<<count(coins, n, k)<<endl;
}

int32_t main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int tcase = 1;
  cin>>tcase;
  for(int i = 1; i<=tcase; i++){

    solution();
  }
}
