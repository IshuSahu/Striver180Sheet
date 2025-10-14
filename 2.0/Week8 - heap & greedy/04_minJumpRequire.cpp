/*
You're given a list of maximum jump lengths at each position, and you need to find the minimum number of jumps required to reach the end.
🔍 Problem Intuition
- You start at index 0.
- At each index i, you can jump to any of the indices in the range [i + 1, i + nums[i]].
- The goal is to reach the last index (n - 1) in the fewest number of jumps.
*/
#include<bits/stdc++.h>

using namespace std;
int dfs(int index, const vector<int>& nums) {
    int n = nums.size();
    if (index >= n - 1) return 0; // Already at or beyond the end

    int minJumps = INT_MAX;
    for (int j = 1; j <= nums[index]; ++j) {
        int next = index + j;
        if (next < n) {
            int jumps = dfs(next, nums);
            if (jumps != INT_MAX)
                minJumps = min(minJumps, 1 + jumps);
        }
    }
    return minJumps;
}
// TC: O(Exponential)
int jumpBruteForce(const vector<int>& nums) {
    return dfs(0, nums);
}

// TC= O(N)
/*
Use a greedy BFS-style level traversal:

Treat the array like levels in a tree.
You keep track of:
- currentEnd: the farthest point of the current jump.
- farthest: the farthest point you can reach in the next jump.
- jumps: the number of jumps made.
- Every time you reach currentEnd, you must jump, and you update the boundary to farthest.
*/
int jump(vector<int>& nums) {
    int jumps = 0;
    int currentEnd = 0;
    int farthest = 0;

    for (int i = 0; i < nums.size() - 1; ++i) {
        farthest = max(farthest, i + nums[i]);

        if (i == currentEnd) {
            jumps++;
            currentEnd = farthest;
            if (currentEnd >= nums.size() - 1) break;
        }
    }
    return jumps;
}
int main() {
    vector<int> nums = {2, 3, 1, 1, 4};
    int result = jumpBruteForce(nums);
    cout << "Minimum jumps (Brute Force): " << result << endl;
    return 0;
}
