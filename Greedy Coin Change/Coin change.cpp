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

    int coins[] = {25, 20, 10, 5, 1};
    int value;

    cout<<"Enter the amount for which you want to find minimum coins: ";
    cin>>value;

    int size = sizeof(coins) / sizeof(coins[0]); // Calculate size of coins array

    int minCount = findMinCoins(coins, size, value);

    cout<<"Total Coins Needed = "<<minCount<<endl;

    cout<<"Coins are: ";
    for(int i=0; i<minCount; i++)
        cout<<ans[i] << " ";

    return 0;
}
