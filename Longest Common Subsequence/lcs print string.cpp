#include <iostream>
#include <vector>
#include <string>

using namespace std;

string longestCommonSubsequence(string t, string k){
    int m = t.length();
    int n = k.length();

    // Create a 2D DP table
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    // Fill the DP table
    for(int i=1; i<=m; i++){
        for(int j=1; j<=n; j++){
            if(t[i - 1] == k[j - 1]){
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    // Reconstruct the LCS
    string lcs;
    int i = m, j = n;
    while(i > 0 && j > 0){
        if(t[i - 1] == k[j - 1]){
            lcs = t[i - 1] + lcs;
            i--;
            j--;
        } else {
            if(dp[i - 1][j] >= dp[i][j - 1]){
                i--;
            } else {
                j--;
            }
        }
    }

    return lcs;
}

int main(){
    string t,k;
    cin>>t>>k;

    string lcs = longestCommonSubsequence(t, k);

    cout<<lcs<<endl;

    return 0;
}
