#include <iostream>
#include <vector>
using namespace std;

int countWays(int amount){

    vector<int> coins = {50, 25, 10, 5, 1};
    
    // Create a 1D DP table to store the number of ways to make change for each amount
    vector<int> dp(amount + 1, 0);
    dp[0] = 1; // Base case: 1 way to make change for 0 cents (using no coins)
    
    // Iterate through each coin denomination
    for (int i = 0; i < coins.size(); ++i){
        int coin = coins[i];
        // Update dp table for current coin
        for (int j=coin; j<=amount; j++){
            dp[j] += dp[j - coin];
        }
    }
    
    // The result for 'amount' cents is stored in dp[amount]
    return dp[amount];
}

int main(){
    int amount;
    while(cin>>amount){
        int ways = countWays(amount);
        cout<<ways<<endl;
    }
    return 0;
}
