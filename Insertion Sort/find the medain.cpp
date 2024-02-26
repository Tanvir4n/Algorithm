#include <bits/stdc++.h>

using namespace std;

void insertionSort(vector<int>& v, int n){
    for(int i=1; i<n; i++){
        int key=v[i];
        int j=i-1;

        while(j >= 0 && v[j] > key){
            v[j+1] = v[j];
            j=j-1;
        }

        v[j+1] = key;
    }
}

int main(){

    int n;
    cin>>n;

    if(n>4 && n>=100){
        return 1;
    }

    vector<int>v(n);

    for(int i=0; i<n; i++){
        cin>>v[i];
    }

    insertionSort(v, n);

    for(int i=0; i<n; i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;

    int mid;
    if(n%2 == 0){
        mid=(n/2) + 1;
    }else{
        mid=(n+1) / 2;
    }

    cout<<v[mid - 1]<<endl;
}
