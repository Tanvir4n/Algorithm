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
// Function to find minimum number of coins needed to make amount V using a greedy approach
vector<int> minCoinsGreedy(int amount, vector<int>& denominations){
   
    vector<int>coinsUsed;

    for(int i=0; i<denominations.size(); i++){
        
        while(amount >= denominations[i]){
            amount -= denominations[i];
            coinsUsed.push_back(denominations[i]);
        }

    }

    return coinsUsed;
}

signed main(){

    Fast();

    int amount;
    cin>>amount;
    vector<int> denominations = {25,10,5,1};

    
    vector<int> coinsUsed = minCoinsGreedy(amount, denominations);

    cout<<"Minimum number of coins needed for amount "<<amount<<": "<<coinsUsed.size()<<endl;

    cout<<"Coins used: ";
    for(int coin : coinsUsed){
        cout<<coin<<" ";
    }
    cout<<endl;
    // cout<<"Coins used: ";
    // for(int i=0; i<coinsUsed.size(); i++){
    //     cout<<coinsUsed[i]<<" ";
    // }
    // cout<<endl;

    return 0;
}
