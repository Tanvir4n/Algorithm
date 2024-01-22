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

void solution(){

    int arr[]={1,2,3,4,5};
    int l=0,r=4;

    while(l<r){
        int temp=0;
        temp=arr[l];
        arr[l]=arr[r];
        arr[r]=temp;
        l++,r--;
    }
    for(int i=0; i<5; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

signed main(){

    ISO();
    solution();
    return 0;
}

