#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Cell {
    int x, y, dist;
};

int shortestDistance(int N, int M, vector<vector<int>> A, int X, int Y) {
    if (A[0][0] == 0) return -1; // Start blocked
    
    vector<vector<int>> visited(N, vector<int>(M, 0));
    queue<Cell> q;
    q.push({0, 0, 0});
    visited[0][0] = 1;
    // Direction setup to move up, down, right, left
    int dx[] = {1, -1, 0, 0};
    int dy[] = {0, 0, 1, -1};
    
    while (!q.empty()) {
        Cell cur = q.front();
        q.pop();
        
        // If we reached destination
        if (cur.x == X && cur.y == Y)
            return cur.dist;
        
        // Explore all 4 directions
        for (int k = 0; k < 4; k++) {
            int nx = cur.x + dx[k];
            int ny = cur.y + dy[k];
            
            if (nx >= 0 && ny >= 0 && nx < N && ny < M &&
                !visited[nx][ny] && A[nx][ny] == 1) {
                visited[nx][ny] = 1;
                q.push({nx, ny, cur.dist + 1});
            }
        }
    }
    return -1; // Destination not reachable
}

int main() {
    vector<vector<int>> A = {
        {1,0,0,0},
        {1,1,0,1},
        {0,1,1,1}
    };
    int X = 2, Y = 3;
    cout << "Shortest Distance: " << shortestDistance(3, 4, A, X, Y) << endl;
    return 0;
}

/*
We are using BFS 
BFS processes nodes in order of increasing distance. level1, level2, level3 sooo on
The first time it reaches the goal → shortest path found.

| Type      | Complexity                           |
| --------- | ------------------------------------ |
| **Time**  | O(N × M) — each cell visited once    |
| **Space** | O(N × M) — for queue + visited array |
*/