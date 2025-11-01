#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution
{
public:
    int orangesRotting(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();

        queue<pair<int, int>> q;
        int fresh = 0;

        // Step 1: Push all initially rotten oranges to queue
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 2)
                    q.push({i, j});
                else if (grid[i][j] == 1)
                    fresh++;
            }
        }

        // If no fresh oranges at all
        if (fresh == 0)
            return 0;

        int minutes = -1;
        int dx[] = {1, -1, 0, 0};
        int dy[] = {0, 0, 1, -1};

        // Step 2: BFS
        while (!q.empty())
        {
            int size = q.size();
            minutes++; // each round = 1 minute

            while (size--)
            {
                pair<int, int> cur = q.front();
                int x = cur.first;
                int y = cur.second;
                q.pop();

                for (int k = 0; k < 4; k++)
                {
                    int nx = x + dx[k];
                    int ny = y + dy[k];

                    if (nx >= 0 && ny >= 0 && nx < n && ny < m && grid[nx][ny] == 1)
                    {
                        grid[nx][ny] = 2;
                        fresh--;
                        q.push({nx, ny});
                    }
                }
            }
        }

        // If some fresh oranges are left → impossible
        return (fresh == 0) ? minutes : -1;
    }
};

int main()
{
    vector<vector<int>> grid = {
        {2, 1, 1},
        {1, 1, 0},
        {0, 1, 1}};

    Solution s;
    cout << "Minimum minutes: " << s.orangesRotting(grid) << endl;
    return 0;
}