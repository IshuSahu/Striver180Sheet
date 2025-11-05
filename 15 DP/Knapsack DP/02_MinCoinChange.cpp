#include <bits/stdc++.h>
using namespace std;

int coinChangeMin(vector<int> &coins, int amount)
{
    int n = coins.size();
    vector<int> dp(amount + 1, INT_MAX);
    dp[0] = 0;

    for (int coin : coins)
    {
        for (int i = coin; i <= amount; i++)
        {
            if (dp[i - coin] != INT_MAX)
                dp[i] = min(dp[i], dp[i - coin] + 1);
        }
    }

    return dp[amount] == INT_MAX ? -1 : dp[amount];
}

int main()
{
    vector<int> coins = {1, 2, 5};
    int amount = 11;
    cout << "Minimum coins required: " << coinChangeMin(coins, amount) << endl;
    return 0;
}

// Number of Ways to Make Amount (Classic Coin Change 2)
/*
#include <bits/stdc++.h>
using namespace std;

int coinChangeWays(vector<int>& coins, int amount) {
    vector<int> dp(amount + 1, 0); // dp[i] = ways to make amount i
    dp[0] = 1; // Only 1 way to make amount 0 (no coins)

    for (int coin : coins) {
        for (int i = coin; i <= amount; i++) {
            dp[i] += dp[i - coin]; // add ways using this coin
        }
    }

    return dp[amount];
}

int main() {
    vector<int> coins = {1, 2, 5};
    int amount = 5;
    cout << "Number of ways to make amount: " << coinChangeWays(coins, amount) << endl;
    return 0;
}

*/