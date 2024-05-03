#include <bits/stdc++.h>

using namespace std;

const int max_coins = 100;

vector<int>ans(max_coins);

int findMinCoins(int coins[], int size, int value){
    int count = 0;

    for(int i=0; i<size; i++){
        // Take as many coins[i] as possible
        while(value >= coins[i]){
            // After taking the coin, reduce the value
            value -= coins[i];
            ans[count] = coins[i];
            count++;
        }
        if(value == 0)
            break;
    }

    return count;
}

int main(){

    int coins[] = {500, 100, 50, 10, 5, 1};
    int value;

    cin>>value;

    int size = sizeof(coins) / sizeof(coins[0]);            // Calculate size of coins array

    int minCount = findMinCoins(coins, size, value);

    //cout<<"Total Coins Needed = "<<minCount<<endl;

    // cout<<"Coins are: ";
    // for(int i=0; i<minCount; i++){
    //     cout<<ans[i] << " ";
    // }

    //cout<<"Coins are: ";
    for(int i=minCount-1; i>=0;  i--){
        cout<<ans[i] << " ";
    }

    return 0;
}

//https://toph.co/p/cash-change
