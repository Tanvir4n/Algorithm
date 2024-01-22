#include <bits/stdc++.h>

using namespace std;

#define int long long
#define ll long long
#define ull unsigned long long
#define ui unsigned int
#define pi acos(-1)
#define pb push_back
#define nl "\n"

void ISO(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void solution(int n){

    vector<int>arr(n);
    for(int i=0; i<n; i++){
        cin>>arr[i];

    }
    sort(arr.begin(), arr.end(), greater<int>());
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

signed main(){

    int n;
    cin>>n;


    ISO();
    solution(n);
    return 0;
}

