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

void ISO(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void solution(){

    vector<int>coins{25,13,9,7,2,1};

    int n,k;
    cin>>n>>k;
    int left=k-n;

    vector<int>usedCoins;
    int remaining=left;

    for(int coin : coins){
        while(remaining >= coin){
            usedCoins.push_back(coin);
            remaining -= coin;
        }
    }
    bool happy = false;
    for(int coin : usedCoins){
        if(coin == 7 || coin == 9){
            happy = true;
            break;
        }
    }
    if(happy){
        cout<<"Happy"<<endl;
    } else {
        cout<<"Sad"<<endl;
    }
     
}
 
signed main(){
 
    ISO();
    solution();


    return 0;
}
