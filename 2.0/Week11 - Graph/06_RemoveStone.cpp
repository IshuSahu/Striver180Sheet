/*
You are given several stones placed on a grid (like a chessboard), each at a coordinate (x, y).

Rule for removal:
You can remove a stone if there is another stone in the same row or same column (sharing x or y coordinate).

Your goal:
👉 Remove as many stones as possible, following the rule above.

At the end, you’ll always have at least one stone left in each connected group of stones.
y →   0   1   2
x ↓  ------------
0 |  ●   ●
1 |  ●       ●
2 |      ●   ●

Core idea:
Count connected groups of stones

Think of it as a network:
If any two stones are connected (directly or through others), they depend on each other — you can remove all but one.

So, the maximum number of stones you can remove = total stones − number of connected groups.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void dfs(int idx, vector<vector<int>>& stones, vector<bool>& visited) {
        visited[idx] = true;
        for (int j = 0; j < stones.size(); j++) {
            if (!visited[j]) {
                // if they share same row or column
                if (stones[idx][0] == stones[j][0] || stones[idx][1] == stones[j][1]) {
                    dfs(j, stones, visited);
                }
            }
        }
    }

    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        vector<bool> visited(n, false);
        int numGroups = 0;

        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                dfs(i, stones, visited);
                numGroups++;
            }
        }

        return n - numGroups; // remove all except one per group
    }
};

int main() {
    Solution sol;
    vector<vector<int>> stones = {{0,0},{0,1},{1,0},{1,2},{2,1},{2,2}};
    cout << sol.removeStones(stones); // Output: 5
    return 0;
}
