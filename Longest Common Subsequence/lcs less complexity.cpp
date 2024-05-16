#include <bits/stdc++.h>
using namespace std;

int lcs(string text1, string text2){
    int m = text1.length();
    int n = text2.length();

    if(m < n){
        swap(text1, text2);
        swap(m, n);
    }

    vector<int> prev(n + 1, 0);
    vector<int> current(n + 1, 0);

    for(int i=1; i<=m; i++){
        for(int j=1; j<=n; j++){
            if(text1[i - 1] == text2[j - 1]){
                current[j] = prev[j - 1] + 1;
            } else {
                current[j] = max(prev[j], current[j - 1]);
            }
        }
        swap(prev, current);
    }

    return prev[n];
}

int main(){
    string line1, line2;

    while(getline(cin, line1)){
        getline(cin, line2);

        int lcs_length = lcs(line1, line2);
        cout<<lcs_length<<endl;
    }

    return 0;
}
/*
Complexity Analysis:
>Time Complexity: The time complexity of this optimized approach is O(m * n) in the worst-case scenario,
where m is the length of the longer string (text1) and n is the length of the shorter string (text2). 
This is because we're still iterating over all characters of both strings once for filling the DP arrays.

>Space Complexity: The space complexity is reduced to O(min(m, n)) due to the use of the two arrays (prev and current) 
of size n + 1. This is a significant improvement over the previous space complexity of O(m * n), particularly when n 
(length of the shorter string) is much smaller than m.
*/
