#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
    {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        vector<vector<int>> dp(m, vector<int>(n, 0));

        // Starting point
        if (obstacleGrid[0][0] == 1)
            return 0;
        dp[0][0] = 1;

        // First column
        for (int i = 1; i < m; ++i)
        {
            if (obstacleGrid[i][0] == 0)
                dp[i][0] = dp[i - 1][0];
        }

        // First row
        for (int j = 1; j < n; ++j)
        {
            if (obstacleGrid[0][j] == 0)
                dp[0][j] = dp[0][j - 1];
        }

        // Fill rest of the dp table
        for (int i = 1; i < m; ++i)
        {
            for (int j = 1; j < n; ++j)
            {
                if (obstacleGrid[i][j] == 0)
                {
                    dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
                }
                else
                {
                    dp[i][j] = 0; // obstacle
                }
            }
        }

        return dp[m - 1][n - 1];
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> grid = {
        {0, 0, 0},
        {0, 1, 1},
        {0, 0, 0}};
    cout << "Unique paths with obstacles: " << sol.uniquePathsWithObstacles(grid) << endl;
    return 0;
}
