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

int mergeAndCount(vector<int>& v, int left, int mid, int right){

    vector<int> temp(right - left + 1); 
    int i = left; 
    int j = mid + 1; 
    int k = 0; 
    
    int inversions = 0; 

    while(i <= mid && j <= right){
        if(v[i] <= v[j]){
            temp[k++] = v[i++];
        } else {
           
            temp[k++] = v[j++];
            inversions += (mid - i + 1); 
        }
    }

    while(i <= mid){
        temp[k++] = v[i++];
    }

    while(j <= right){
        temp[k++] = v[j++];
    }

    for(i=left, k=0; i<=right; i++, k++){
        v[i] = temp[k];
    }

    return inversions;
}

int mergeSortCount(vector<int>& v, int left, int right){
    int inversions = 0;

    if (left < right){
        int mid = left + (right - left) / 2;

        inversions += mergeSortCount(v, left, mid);
        inversions += mergeSortCount(v, mid + 1, right);

        inversions += mergeAndCount(v, left, mid, right);
    }

    return inversions;
}

signed main(){

    Fast();
    //solution();
    
    int t;
    cin>>t;

    while(t--){
        int n;
        cin>>n;

        vector<int>v(n);
        for(int i=0; i<n; i++){
            cin>>v[i];
        }
        int swap_count = mergeSortCount(v, 0, n - 1);

        cout<<swap_count<<endl;
    }

    return 0;
}

// https://vjudge.net/problem/SPOJ-CODESPTB
