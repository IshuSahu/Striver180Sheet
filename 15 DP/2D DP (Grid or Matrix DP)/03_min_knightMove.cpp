/*
Problem Statement:
You are given a chessboard of size n x n, and a knight piece is placed at a starting position (x1, y1).
You are also given a target position (x2, y2).

A knight moves in an "L" shape:
 - 2 steps in one direction and 1 step in a perpendicular direction.
 - Total of 8 possible moves from any given position.

Goal:
Find the minimum number of moves a knight needs to reach the target position from the starting position.
*/

#include <iostream>
#include <queue>
#include <vector>
#include <unordered_map>

using namespace std;
// All 8 knight moves
vector<pair<int, int>> directions = {
    {2, 1}, {2, -1}, {-2, 1}, {-2, -1}, {1, 2}, {1, -2}, {-1, 2}, {-1, -2}};

bool isValid(int x, int y, int n)
{
    return x >= 0 && y >= 0 && x < n && y < n;
}

// BFS Approch
int minKnightMovesBFS(int n, int x1, int y1, int x2, int y2)
{
    vector<vector<bool>> visited(n, vector<bool>(n, false));
    queue<pair<pair<int, int>, int>> q; // ((x, y), steps)

    q.push({{x1, y1}, 0});
    visited[x1][y1] = true;

    while (!q.empty())
    {
        auto current = q.front();
        q.pop();

        int x = current.first.first;
        int y = current.first.second;
        int steps = current.second;

        if (x == x2 && y == y2)
            return steps;

        for (auto dir : directions)
        {
            int nx = x + dir.first;
            int ny = y + dir.second;

            if (isValid(nx, ny, n) && !visited[nx][ny])
            {
                visited[nx][ny] = true;
                q.push({{nx, ny}, steps + 1});
            }
        }
    }

    return -1; 
}
/*
TC = O(n^2) Each cell is visited at most once → O(n^2), For each cell, we check 8 directions → O(8 * n^2) = O(n^2)
SC = O(n^2) visited matrix → O(n^2)
*/

// DP approch
unordered_map<string, int> memo;

int minKnightMoves(int x, int y)
{
    x = abs(x);
    y = abs(y);
    string key = to_string(x) + "," + to_string(y);

     // check if result is already computed. eg: Check memo["2,1"] = 1;
    if (memo.count(key))
        return memo[key];

    // Base cases
    if (x == 0 && y == 0)
        return 0;
    if (x + y == 2)
        return 2; // (1,1), (0,2), (2,0)

    // Recur with memoization
    int res = 1 + min(
                      minKnightMoves(abs(x - 1), abs(y - 2)),
                      minKnightMoves(abs(x - 2), abs(y - 1)));

    memo[key] = res;
    return res;
}
/*
TC = O(x*y) Each unique (x,y) pair is computed once
SC = O(x*y) Memoization storage → O(x*y) in worst case
*/

int main()
{
    int n = 8;
    int startX = 0, startY = 0;
    int targetX = 7, targetY = 7;

    // cout << "Minimum knight moves : " << minKnightMovesBFS(n, startX, startY, targetX, targetY) << endl;

    cout << "Moves to reach (5, 5): " << minKnightMoves(5, 5) << endl;
    cout << "Moves to reach (2, 1): " << minKnightMoves(2, 1) << endl;
    // cout << "Moves to reach (100, 100): " << minKnightMoves(100, 100) << endl;
    return 0;
}
