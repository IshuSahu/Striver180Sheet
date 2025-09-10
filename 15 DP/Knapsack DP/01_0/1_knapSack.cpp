#include <iostream>
#include <vector>
using namespace std;

int knapsack(int n, int W, vector<int>& wt, vector<int>& val) {
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));
    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            if (i == 0 || w == 0) {
                dp[i][w] = 0;
            } 
            else if (wt[i - 1] <= w) {
                dp[i][w] = max(val[i - 1] + dp[i - 1][w - wt[i - 1]], dp[i - 1][w]);
            } 
            else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }
    return dp[n][W];
}

/*
| i \ w | 0 | 1 | 2  | 3  | 4  |
| ----- | - | - | -- | -- | -- |
| 0     | 0 | 0 | 0  | 0  | 0  |
| 1     | 0 | 6 | 6  | 6  | 6  |
| 2     | 0 | 6 | 10 | 16 | 16 |
| 3     | 0 | 6 | 10 | 16 | 18 |

*/
int main() {
    int n = 3;
    int W = 4;
    vector<int> wt = {1, 2, 3};
    vector<int> val = {6, 10, 12};
    int maxValue = knapsack(n, W, wt, val);
    cout << "Maximum value in Knapsack = " << maxValue << endl;
    return 0;
}
