#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void FastIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

pair<int, vector<int>> longestDecreasingSubsequence(vector<int>& weights){
    int n = weights.size();
    if(n == 0)
        return {0, {}};

    vector<int> dp; // This will store the decreasing subsequence

    for(int weight : weights){
        auto it = lower_bound(dp.begin(), dp.end(), weight, greater<int>()); // Use lower_bound with greater comparator for LDS
        if(it == dp.end())
            dp.push_back(weight);
        else
            *it = weight;
    }

    // Reconstruct the LDS sequence
    vector<int> lds;
    for(int i = n - 1; i >= 0; i--){
        if(!dp.empty() && weights[i] == dp.back()){
            lds.push_back(weights[i]);
            dp.pop_back();
        }
    }
    reverse(lds.begin(), lds.end());

    return {(int)lds.size(), lds};
}

int main(){
    FastIO();

    int n;
    cin >> n;

    vector<int> weights(n);
    for(int i = 0; i < n; i++){
        cin >> weights[i];
    }

    auto result = longestDecreasingSubsequence(weights);

    int lds_length = result.first;
    vector<int> lds_sequence = result.second;

    cout << "Length of LDS: " << lds_length << endl;
    cout << "LDS Sequence: ";
    for (int i = 0; i < lds_sequence.size(); i++) {
        cout << lds_sequence[i];
        if (i != lds_sequence.size() - 1)
            cout << " ";
    }
    cout << endl;

    return 0;
}
