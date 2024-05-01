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

// void Fast(){
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
//     cout.tie(NULL);
// }

// Function to find the length of the longest common subsequence
int lcs(string text1, string text2){
    int m = text1.length();
    int n = text2.length();

    // Create a 2D DP array to store the length of longest common subsequence
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    // Fill dp array according to LCS algorithm
    for(int i=1; i<=m; i++){
        for(int j=1; j<=n; j++){
            if(text1[i - 1] == text2[j - 1]){
                dp[i][j] = dp[i - 1][j - 1] + 1; // characters match, extend LCS
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]); // characters don't match
            }
        }
    }

    return dp[m][n]; // return the length of LCS
}

signed main(){

    // Fast();

    string line1, line2;
    
    // Read input until EOF (end-of-file)
    while(getline(cin, line1)){
        getline(cin, line2);

        // Calculate LCS length for the current pair of strings
        int lcs_length = lcs(line1, line2);

        // Output the length of the LCS
        cout<<lcs_length<<endl;
    }

    return 0;
}
