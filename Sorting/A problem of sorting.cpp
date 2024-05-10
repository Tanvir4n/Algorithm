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
    
    for(int i=0; i<t; i++){
        int n;
        cin>>n;
        
        vector<pair<string, int>>peopleB(n);
        for(int i=0; i<n; i++){
            cin>>peopleB[i].first>>peopleB[i].second;
        }

        sort(peopleB.rbegin(), peopleB.rend());
    
    for(auto person : peopleB){
        cout<<person.first<<endl;
    }
    
    }
    
}
 
signed main(){
 
    Fast();
    solution();
 	


    return 0;
}

// https://vjudge.net/problem/HDU-5427
