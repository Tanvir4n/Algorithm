/*
Mr. X is a student of Computer Science. He is facing a problem and  needs your help to solve it.
The problem is, you will be given N integer numbers( 4<n<=100) which are arranged side by side (x1,x2,x3,x4,.....).
Now you have to sort those items in ascending order. After doing this , your job is to print the items in a sorted way and find the median.
[NB: when N is odd  , Median= (N+1)/2; When N is even Median= (N/2)+1 ]

Sample Input: 
7
4 7 11 2 9 3 5
Sample Output:
2 3 4 5 7 9 11
5
*/

#include <bits/stdc++.h>

using namespace std;

void ss(vector<int>& v, int n){
    for(int i=0; i<n-1; i++){
        int minIndex=i;
        for(int j=i+1; j<n; j++){
            if(v[j] < v[minIndex]){
                minIndex=j;
            }
        }
        swap(v[i], v[minIndex]);
    }
}

int main(){
    
    int n;
    cin>>n;
    
    if(n > 4 && n >= 100){
        return 1;
    }
    vector<int>v(n);
    
    for(int i=0; i<n; i++){
        cin>>v[i];
    }
    ss(v,n);
    
    for(int i=0; i<n; i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
    
    int mid;
    if(n%2 == 0){
        //mid=(v[n/2-1] + v[n/2])/2;
        //mid=v[n/2]/2;
        mid=(n/2)+1;
    }
    else{
        //mid=v[n/2];
        //mid=v[n/2];
        mid=(n+1)/2;
    }
    cout<<v[mid-1]<<endl;
}
