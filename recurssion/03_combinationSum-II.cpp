#include <bits/stdc++.h>

using namespace std;
class Solution
{
public:
    // void findCombination(int ind, int target, vector<int> &arr, vector<vector<int>> &ans, vector<int> &ds)
    // {

    //     if (target == 0)
    //     {
    //         ans.push_back(ds);
    //         return;
    //     }
    //     for (int i = ind; i < arr.size(); i++)
    //     {
    //         if (i > ind && arr[i] == arr[i - 1])
    //             continue;
    //         if (arr[i] > target)
    //             break;
    //         ds.push_back(arr[i]);
    //         findCombination(i + 1, target - arr[i], arr, ans, ds);
    //         ds.pop_back();
    //     }
    // }
    // vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    // {
    //     sort(candidates.begin(), candidates.end());
    //     vector<vector<int>> ans;
    //     vector<int> ds;
    //     findCombination(0, target, candidates, ans, ds);
    //     return ans;
    // }
    void helper(int ind, int T, vector<int> &nums, set<vector<int>> &res, vector<int> &temp)
    {
        if (T == 0)
        {
            // sort(temp.begin(), temp.end());
            res.insert(temp);
        }
        if (ind == nums.size() || T < 0)
        {
            return;
        }

        if (nums[ind] <= T)
        {
            temp.push_back(nums[ind]);
            helper(ind + 1, T - nums[ind], nums, res, temp);
            temp.pop_back();
        }
        helper(ind + 1, T, nums, res, temp);
    }
    vector<vector<int>> combinationSum(vector<int> &nums, int T)
    {
        vector<vector<int>> ans;
        vector<int> temp;
        set<vector<int>> res;
        helper(0, T, nums, res, temp);
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
    vector<int> v{2, 5, 2, 1, 2};
    int target = 5;

    vector<vector<int>> ans = obj.combinationSum(v, target);
    cout << "Combinations are: " << endl;
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
            cout << ans[i][j] << " ";
        cout << endl;
    }
}