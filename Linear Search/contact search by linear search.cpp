#include <bits/stdc++.h>

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

    cout<<"Enter name : "<<endl;

    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    string target;
    cout<<"Enter the searching name : ";
    cin>>target;

    int result = linear_search(n, arr, target);

    if(result != -1){
        cout<<"String '"<<target<<"'found at index"<<result<<endl;
    }
    else{
        cout<<"String"<<target<<"not found"<<endl;
    }

    return 0;

}
