#include <iostream>
#include <vector>
#include <algorithm>
#include <climits> // for INT_MAX

using namespace std;

class Solution
{
public:
    int minPath(int i, int j, int m, int n, vector<vector<int>> &grid, vector<vector<int>> &dp)
    {
        if (i == m - 1 && j == n - 1)
            return grid[i][j];

        if (i >= m || j >= n)
            return INT_MAX;

        // Return cached result if already computed
        if (dp[i][j] != -1)
            return dp[i][j];

        int down = minPath(i + 1, j, m, n, grid, dp);
        int right = minPath(i, j + 1, m, n, grid, dp);

        dp[i][j] = grid[i][j] + min(down, right);
        return dp[i][j];
    }

    int minPathSum(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> dp(m, vector<int>(n, -1));
        return minPath(0, 0, m, n, grid, dp);
    }
};
int main()
{
    Solution sol;

    vector<vector<int>> grid = {
        {1, 3, 1},
        {1, 5, 1},
        {4, 2, 1}};

    cout << "Minimum path sum: " << sol.minPathSum(grid) << endl;
    return 0;
}
