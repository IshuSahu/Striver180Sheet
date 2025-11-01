/*
You have a binary grid of 0s and 1s. For every cell, you want to calculate:
How far is the nearest 1?
Distance between (i1, j1) and (i2, j2) is Manhattan distance: |i1 - i2| + |j1 - j2|.
Return a matrix of the same size with these minimum distances.
EG:
grid = [[0, 1, 1, 0],
        [1, 1, 0, 0],
        [0, 0, 1, 1]]

output:
[[1, 0, 0, 1],
 [0, 0, 1, 1],
 [1, 1, 0, 0]]
Explanation:
    - (0,0) → nearest 1 is (0,1) → distance 1
    - (0,1) → is itself 1 → distance 0
    - (1,2) → nearest 1 is (0,2) → distance 1
    And so on…
*/

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> nearest(vector<vector<int>> grid)
{
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> dist(n, vector<int>(m, -1));
    queue<pair<int, int>> q;

    // Step 1: Push all 1's to queue, distance = 0
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == 1)
            {
                q.push({i, j});
                dist[i][j] = 0;
            }
        }
    }

    int dx[] = {1, -1, 0, 0};
    int dy[] = {0, 0, 1, -1};

    // Step 2: BFSs
    while (!q.empty())
    {
        auto cur = q.front();
        q.pop();
        int x = cur.first;
        int y = cur.second;

        for (int k = 0; k < 4; k++)
        {
            int nx = x + dx[k];
            int ny = y + dy[k];

            if (nx >= 0 && ny >= 0 && nx < n && ny < m && dist[nx][ny] == -1)
            {
                dist[nx][ny] = dist[x][y] + 1;
                q.push({nx, ny});
            }
        }
    }

    return dist;
}

int main()
{
    vector<vector<int>> grid = {{0, 1, 1, 0}, {1, 1, 0, 0}, {0, 0, 1, 1}};
    vector<vector<int>> res = nearest(grid);

    for (auto &row : res)
    {
        for (int val : row)
            cout << val << " ";
        cout << endl;
    }
}

/*
Approach — BFS (Multi-Source)

This is very similar to the rotting oranges problem:
 - All 1s are sources (like rotten oranges).
 - Use BFS to expand level by level.
 - For each 0, the first time you reach it, you’ve found the nearest 1.
 - Fill the distance matrix accordingly.

Why BFS works:
 - BFS finds the shortest path in an unweighted grid, so the first time we reach a 0, it’s guaranteed to be the minimum distance.
*/