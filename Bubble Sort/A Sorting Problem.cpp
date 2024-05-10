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

void bubble_sort(int n, vector<int>&v){

    int swaps=0;

    for(int i=0; i<n-1; i++){
        for(int j=0; j<n-i-1; j++){
            if(v[j]>v[j+1]){
                swap(v[j], v[j+1]);
                    swaps++;
            }
        }
    }
    // to print the sorted array
    // for(int i=0; i<n; i++){
    //     cout<<v[i]<<" ";
    // }
    // cout<<nl;
    cout<<swaps<<nl;
}
 
signed main(){
 
    Fast();
 	
    int n;
    cin>>n;

    vector<int>v(n);
    for(int i=0; i<n; i++){
        cin>>v[i];
    }
    
    bubble_sort(n, v);

    return 0;
}

// https://vjudge.net/problem/Baekjoon-23336
