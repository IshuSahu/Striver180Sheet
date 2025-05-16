#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    // Brute force solution
    // int countPaths(int i, int j, int n, int m)
    // {
    //     if (i == (n - 1) && j == (m - 1))
    //         return 1;
    //     if (i >= n || j >= m)
    //         return 0;
    //     else
    //         return countPaths(i + 1, j, n, m) + countPaths(i, j + 1, n, m);
    // }

    // int uniquePaths(int m, int n)
    // {
    //     return countPaths(0, 0, m, n);
    // }

    int countPaths(int i, int j, int n, int m, vector<vector<int>> &dp)
    {
        if (i == (n - 1) && j == (m - 1))
            return 1;
        if (i >= n || j >= m)
            return 0;
        if (dp[i][j] != -1)
            return dp[i][j];
        else
            return dp[i][j] = countPaths(i + 1, j, n, m, dp) + countPaths(i, j + 1, n, m, dp);
    }
    int uniquePaths(int m, int n)
    {
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));
        /*
        [
          [-1, -1, -1, -1],  // row 0
          [-1, -1, -1, -1],  // row 1
          [-1, -1, -1, -1]   // row 2
        ]
        */
        // dp[1][1]=1;
        int num = countPaths(0, 0, m, n, dp);
        if (m == 1 && n == 1)
            return num;
        return dp[0][0];
    }

    // TC=SC (M*N)
};
int main()
{
    Solution obj;
    int totalCount = obj.uniquePaths(3, 3);
    cout << "The total number of Unique Paths are " << totalCount << endl;
}