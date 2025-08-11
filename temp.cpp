#include <bits/stdc++.h>

using namespace std;
class Solution
{
public:
    void helper(vector<int> &nums, set<vector<int>> &res, vector<int> output, int ind)
    {
        if (ind >= nums.size())
        {
            sort(output.begin(), output.end());
            res.insert(output);
            return;
        }

        // exclude
        helper(nums, res, output, ind + 1);

        // include
        int element = nums[ind];
        output.push_back(element);
        helper(nums, res, output, ind + 1);
    }
    vector<vector<int>> subsetsWithDup(vector<int> &nums)
    {
        vector<vector<int>> ans;
        set<vector<int>> res;
        vector<int> output;
        helper(nums, res, output, 0);
        for (auto it = res.begin(); it != res.end(); it++)
        {
            ans.push_back(*it);
        }
        return ans;
    }
};
int main()
{
    Solution obj;
    vector<int> nums = {1, 2, 2};
    vector<vector<int>> ans = obj.subsetsWithDup(nums);
    for (auto res : ans)
    {
        cout << "{";
        for (auto val : res)
        {
            cout << val << " ";
        }
        cout << "}";
    }
    return 0;
}