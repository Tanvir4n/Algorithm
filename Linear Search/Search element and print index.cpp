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

int linear_search(int n, vector<int>&arr, int target){

    for(int i=0; i<n; i++){
        if(arr[i] == target){
            return i;                               
        }
    }
    return -1;                                    
}
 
signed main(){
    
    ISO();

    int n,target;
    cin>>n>>target;
    
    vector<int>arr(n);
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    int result=linear_search(n, arr, target);
    
    if(result != -1){
        cout<<"Index :"<<result<<endl;
    }
    else{
        cout<<"Element not found"<<endl;
    }
    return 0;
}
