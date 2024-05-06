#include <bits/stdc++.h>

using namespace std;

//#define int long long
#define ll long long
#define ull unsigned long long
#define ui unsigned int
#define pi acos(-1)
#define pb push_back
#define endl "\n"
#define nl "\n"

const int INF = numeric_limits<int>::max();

void Fast(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int solution(int n, const vector<int>& deno){

    vector<int> dp(n + 1, INF);
    dp[0] = 0; 

    for(int i=1; i<=n; i++){
        for(int coin : deno){
            if(i >= coin){
                if(dp[i - coin] != INF){
                    dp[i] = min(dp[i], dp[i - coin] + 1);
                }
            }
        }
    }

    return dp[n];
}

int main(){

    Fast();

    int n,m;
    cin>>n>>m;

    vector<int> deno(m);
    for(int i=0; i<m; i++){
        cin>>deno[i];
    }

    int ways = solution(n, deno);
    cout<<ways<<endl;

    return 0;
}

/https://vjudge.net/problem/Aizu-DPL_1_A
