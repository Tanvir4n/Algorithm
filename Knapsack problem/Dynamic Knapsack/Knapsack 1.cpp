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

void solution(){
    
    int n,w;
    cin>>n>>w;

    vector<int>weight(n);
    vector<int>values(n);

    for(int i=0; i<n; i++){
        cin>>weight[i]>>values[i];
    }

    vector<ll>dp(w+1, 0);
    for(int i=0; i<n; i++){
        int itemWeight = weight[i];
        int value = values[i];

        for(int j=w; j>=itemWeight; j--){
            dp[j] = max(dp[j], dp[j - itemWeight] + value);
        }

    }

    cout<<dp[w]<<endl;
}
 
signed main(){
 
    ISO();
    solution();
 	


    return 0;
}
