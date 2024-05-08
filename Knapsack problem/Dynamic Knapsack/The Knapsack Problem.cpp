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

int knapsack(int s, vector<pair<int, int>>& item){
    
    vector<vector<int>>dp(item.size()+1, vector<int>(s+1, 0));

    for(int i=1; i<=item.size(); i++){
        for(int j=1; j<=s; j++){
            if(item[i-1].first <= j){
                dp[i][j] = max(item[i-1].second + dp[i-1][j-item[i-1].first], dp[i-1][j]);
            } else {
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    return dp[item.size()][s];
    
}
 
signed main(){
 
    ISO();
    //solution();
 	
    int s,n;
    cin>>s>>n;
    vector<pair<int, int>>items(n);
    for(int i=0; i<n; i++){
        int size,value;
        cin>>size>>value;
        items[i] = make_pair(size, value);
    }
    int maxValue = knapsack(s, items);
    cout<<maxValue<<endl;

    return 0;
}
// https://vjudge.net/problem/SPOJ-KNAPSACK#author=CSE_CU_18
