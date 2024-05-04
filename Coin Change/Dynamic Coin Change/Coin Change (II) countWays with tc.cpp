#include <iostream>
#include <vector>

using namespace std;

const int MOD = 100000007;

void Fast(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int solution(int k, const vector<int>& deno){

    vector<int> dp(k + 1, 0);
    dp[0] = 1; 

    for(int coin : deno){
        for(int j=coin; j<=k; j++){
            dp[j] = (dp[j] + dp[j - coin]) % MOD;
        }
        
    }

    return dp[k];
}

int main(){

    Fast();

    int t;
    cin>>t;

    for(int i=1; i<=t; i++){
        int n,k;
        cin>>n>>k;

        vector<int> deno(n);
        for(int j=0; j<n; j++){
            cin>>deno[j];
        }

        int ways = solution(k, deno);
        cout<<"Case "<<i<<": "<<ways<<endl;
    }

    return 0;
}
