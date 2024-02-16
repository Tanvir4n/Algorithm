#include<bits/stdc++.h>

using namespace std;

void selection_sort(vector<int>& arr, int n){
    for(int i=0; i<n-1; i++){
        int minIndex = i;
        for(int j=i+1; j<n; j++){
            if(arr[j] < arr[minIndex]){
                minIndex = j;
            }
        }
        swap(arr[i], arr[minIndex]);
    }
}

int main(){
    int n;
    cin>>n;

    if(n<=4 || n>100){
        return 1;
    }

    vector<int> arr(n);

    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    selection_sort(arr, n);

    for(int i=0; i<n; i++) {
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    int mid;

    if(n%2 == 0){
        mid = (arr[n/2 - 1] + arr[n/2]) / 2;
        
    }
    else{
        mid = arr[n/2];
    }

    cout<<mid<<endl;

    return 0;
    
}
