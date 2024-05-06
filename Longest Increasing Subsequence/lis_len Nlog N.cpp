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

int lislen(vector<int>& weights){
    
    int n = weights.size();
    if (n == 0)
        return 0;

    vector<int> dp;
    
    for(int weight : weights){
        auto it = lower_bound(dp.begin(), dp.end(), weight);
        if(it == dp.end())
            dp.push_back(weight);
        else
            *it = weight;
    }
    
    return dp.size();
}

signed main(){

    Fast();

    int N;
    cin>>N;

    vector<int>weights(N);
    for(int i=0; i<N; i++){
        cin>>weights[i];
    }
    
    int lis_length = lislen(weights);
    cout<<lis_length<<endl;

    return 0;
}
// This approach has a time complexity of O(N log N), which is suitable for the maximum constraint of N = 2 * 10^5.
