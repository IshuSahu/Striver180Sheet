#include <bits/stdc++.h>

using namespace std;
//DP approch
// class Solution
// {
//     int helper(vector<int> &nums, int left, int right, vector<vector<int>> &DP)
//     {
//         if (left > right)
//             return 0;
//         if (DP[left][right] != INT_MIN)
//             return DP[left][right];

//         int pickLeft = nums[left] - helper(nums, left + 1, right, DP);
//         int pickRight = nums[right] - helper(nums, left, right - 1, DP);
    
//         DP[left][right] = max(pickLeft, pickRight);
//         return DP[left][right];
//     }
//     public:
//     bool predictTheWinner(vector<int> &nums)
//     {
//         int n = nums.size();
//         vector<vector<int>> DP(n, vector<int>(n, INT_MIN));
//         int score = helper(nums, 0, n - 1, DP);
//         return score >= 0;
//     }
// };


// Gredy Approch but does not give solution always
class Solution
{
    int helper(vector<int> &nums, int left, int right, bool p1)
    {
        if (left > right)
            return 0;
        if (p1)
        {
            int pickLeft = nums[left] + helper(nums, left + 1, right, false);
            int pickRight = nums[right] + helper(nums, left, right - 1, false);
            return max(pickLeft, pickRight);
        }
        else
        {
            int pickLeft = helper(nums, left + 1, right, true);
            int pickRight = helper(nums, left, right - 1, true);
            return min(pickLeft, pickRight);
        }
    }

public:
    bool predictTheWinner(vector<int> &nums)
    {
        int score = helper(nums, 0, nums.size() - 1, true);
        return score >= 0;
    }
};
int main()
{
    Solution solution;

    // Example 1
    vector<int> nums1 = {1, 5, 2};
    bool result1 = solution.predictTheWinner(nums1);
    cout << "Can Player 1 win with nums1? " << (result1 ? "Yes" : "No") << endl;

    // Example 2
    vector<int> nums2 = {1, 5, 233, 7};
    bool result2 = solution.predictTheWinner(nums2);
    cout << "Can Player 1 win with nums2? " << (result2 ? "Yes" : "No") << endl;

    return 0;
}