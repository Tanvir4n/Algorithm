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

void solution(){
    int t;
    cin>>t;

    while(t--){
        int n;
        cin>>n;

        vector<pair<int, int>>points(n);

        for(int i=0; i<n; i++){
            cin>>points[i].first>>points[i].second;
        }
        sort(points.begin(), points.end(), [](const pair<int, int>& a, const pair<int, int>& b){
            if (a.first == b.first){
                return a.second > b.second; // Sort by y if x's are equal and y's are greater
            }
                return a.first < b.first; // Sort by x otherwise
        });

        for(int i=0; i<n; i++){
            cout<<points[i].first<<" "<<points[i].second<<endl;
        }

    }

}

signed main(){
    Fast();
    solution();


    return 0;
}

// https://vjudge.net/contest/575137#problem/A
