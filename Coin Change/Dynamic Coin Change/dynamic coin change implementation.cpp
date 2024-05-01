#include <iostream>
#include <vector>

using namespace std;

int coinChangeWays(vector<int>& coins, int amount) {
    vector<int> dp(amount + 1, 0);
    dp[0] = 1;

    for (int coin : coins) {
        for (int j = coin; j <= amount; j++) {
            dp[j] += dp[j - coin];
        }
    }

    return dp[amount];
}

int main() {
    int n; // Number of coin denominations
    cout << "Enter the number of coin denominations: ";
    cin >> n;

    vector<int> coins(n);
    cout << "Enter the coin denominations: ";
    for (int i = 0; i < n; i++) {
        cin >> coins[i];
    }

    int amount;
    cout << "Enter the amount to make change for: ";
    cin >> amount;

    int ways = coinChangeWays(coins, amount);

    cout << "Number of ways to make change for " << amount << " using given coins: " << ways << endl;

    return 0;
}
