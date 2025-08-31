/*
You're climbing a staircase. It takes n steps to reach the top.
Each time you can either:
climb 1 step, or
climb 2 steps.

Question: How many distinct ways can you climb to the top?
*/

#include <bits/stdc++.h>

using namespace std;
int ways(int n, vector<int> &dp)
{
    if (n == 0 || n == 1)
        return 1;

    if (dp[n] != -1) // returning the memorize value 
        return dp[n];
    dp[n] = ways(n - 1, dp) + ways(n - 2, dp);
    return dp[n];
}
int main()
{
    int n = 3;
    vector<int> dp(n + 1, -1); // n+1 why? You're computing ways(n), need dp[n]
    cout << "Ways to climb " << n << " stairs: " << ways(n, dp) << endl;
    return 0;
}