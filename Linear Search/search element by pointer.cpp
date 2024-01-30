#include<bits/stdc++.h>

using namespace std;

int linear_search(int *p, int n, int value){

    for(int i=0; i<n; i++){
        if(*(p + i) == value){
            return i;
        }
    }
    return -1;
}

int main(){

    int n;
    cout<<"Enter the array size: ";
    cin>>n;

    int arr[n];

    cout<<"Enter elements of the array: ";
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    int *p = arr;

    int value;
    cout<<"Enter the search element: ";
    cin>>value;

    int result = linear_search(p, n, value);

    if(result == -1){
        cout<<"Element not found"<<endl;
    }
    else{
        cout<<"Found element at index "<<result<<endl;
    }
    return 0;
}
