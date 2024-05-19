#include<bits/stdc++.h>

using namespace std;

#define int long long
#define endl "\n"

void FastIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void solution(){

   int t;
   cin>>t;
   vector<pair<int, int>>v(t);
   for(int i=0; i<t; i++){
       cin>>v[i].first>>v[i].second;
   }
   sort(v.begin(), v.end());
   for(int i=0; i<t; i++){
       cout<<v[i].first<<" "<<v[i].second<<endl;
   }
}

int32_t main(){
    FastIO();
    
    solution();
}
// -----------------------------------------------
#include<bits/stdc++.h>

using namespace std;

#define int long long
#define endl "\n"

void FastIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void solution(){

   int t;
   cin>>t;
   vector<pair<int, int>>v;
   for(int i=0; i<t; i++){
       int x,y;
       cin>>x>>y;
        v.push_back(make_pair(x, y));
   }
   sort(v.begin(), v.end());
   for(int i=0; i<t; i++){
       cout<<v[i].first<<" "<<v[i].second<<endl;
   }
}

int32_t main(){
    FastIO();
    
    solution();
}
