#include<bits/stdc++.h>

using namespace std;

int linear_search(int n, vector<string>&arr, string target){
    
    for(int i=0; i<n; i++){
        if(arr[i] == target){
            return i;
        }
    }
    return -1;
}

int main(){
    int n;
    cin>>n;
    
    vector<string>arr(n);
    
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    string target;
    cin>>target;
    
    int result=linear_search(n, arr, target);
    
    if(result == 1){
        cout<<"Matched"<<endl;
    }
    else{
        cout<<"Not Matched"<<endl;
    }
    
    
}
