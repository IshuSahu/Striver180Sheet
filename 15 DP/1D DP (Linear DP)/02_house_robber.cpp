
#include <iostream>
#include <vector>
using namespace std;

int robFrom(int i, vector<int>& nums, vector<int>& dp) {
    if (i >= nums.size()) return 0;

    if (dp[i] != -1) return dp[i];

    // Option 1: Rob current house, skip next
    int rob = nums[i] + robFrom(i + 2, nums, dp);
    // Option 2: Skip current house
    int skip = robFrom(i + 1, nums, dp);

    // Take the max of both options
    dp[i] = max(rob, skip);
    return dp[i];
}

int rob(vector<int>& nums) {
    int n = nums.size();
    vector<int> dp(n, -1);
    return robFrom(0, nums, dp);
}
/*
TC: O(n) → Each index i is computed once and stored in dp, making the total work linear.
SC: O(n) → For the dp array (recursion stack is also O(n) in worst case).
*/

int main() {
    vector<int> nums = {2, 7, 9, 3, 1};
    cout << "Max money that can be robbed: " << rob(nums) << endl;
    return 0;
}
