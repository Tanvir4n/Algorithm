#include <bits/stdc++.h>

using namespace std;

void Fast(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int longestDecreasingSubsequence(vector<int>& weights){
    int n = weights.size();
    if(n == 0)
        return 0;

    // Reverse the array
    reverse(weights.begin(), weights.end());

    vector<int> dp;

    for(int weight : weights){
        auto it = upper_bound(dp.begin(), dp.end(), weight); // Use upper_bound for LDS
        if(it == dp.end())
            dp.push_back(weight);
        else
            *it = weight;
    }

    return dp.size();
}

int main(){
    Fast();

    int n;
    cin>>n;

    vector<int> weights(n);
    for(int i=0; i<n; i++){
        cin>>weights[i];
    }

    int lds_length = longestDecreasingSubsequence(weights);
    cout<<lds_length<<endl;

    return 0;
}
