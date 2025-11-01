#include <iostream>
#include <vector>
using namespace std;
/*
⚙️ How to Solve It
We can use Depth First Search (DFS) — same as exploring a graph:
    1. Loop through each cell in the grid.
    2. When you find a '1' (land):
        - Count it as one island.
        - Use DFS to mark all connected lands (convert '1' → '0') so we don’t count them again.
    3. Continue until all cells are checked.
*/
void dfs(vector<vector<char>>& grid, int i, int j) {
    int m = grid.size();
    int n = grid[0].size();
    
    if (i < 0 || j < 0 || i >= m || j >= n || grid[i][j] == '0')
        return;

    grid[i][j] = '0';

    // Visit all 4 directions, Mark all the 1 --> 0
    dfs(grid, i + 1, j); // down
    dfs(grid, i - 1, j); // up
    dfs(grid, i, j + 1); // right
    dfs(grid, i, j - 1); // left
}

int numIslands(vector<vector<char>>& grid) {
    if (grid.empty()) return 0;
    int m = grid.size();
    int n = grid[0].size();
    int count = 0;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == '1') {
                count++;
                dfs(grid, i, j); // Mark all connected land
            }
        }
    }
    return count;
}

int main() {
    vector<vector<char>> grid = {
        {'1','1','0','0','0'},
        {'1','1','0','0','0'},
        {'0','0','1','0','0'},
        {'0','0','0','1','1'}
    };

    cout << "Number of Islands: " << numIslands(grid) << endl;

    return 0;
}
/*
Time Complexity → O(m × n) 
Space Complexity → O(m × n) 
*/
