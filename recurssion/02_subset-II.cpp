#include <bits/stdc++.h>
/*
roblem Statement: Given an array of integers that may contain duplicates the task is to return all possible subsets. Return only unique subsets and they can be in any order.
Input: array[] = [1,2,2]
Output: [ [ ],[1],[1,2],[1,2,2],[2],[2,2] ]
*/
using namespace std;
void printAns(vector<vector<int>> &ans)
{
    cout << "The unique subsets are " << endl;
    cout << "{ ";
    for (int i = 0; i < ans.size(); i++)
    {
        cout << "[ ";
        for (int j = 0; j < ans[i].size(); j++)
            cout << ans[i][j] << " ";
        cout << "]";
    }
    cout << " }";
}
class Solution
{
public:
    void fun(vector<int> &nums, int index, vector<int> ds, set<vector<int>> &res)
    {
        if (index == nums.size())
        {
            sort(ds.begin(), ds.end());
            res.insert(ds);
            return;
        }
        fun(nums, index + 1, ds, res);
        ds.push_back(nums[index]);
        fun(nums, index + 1, ds, res);
    }
    vector<vector<int>> subsetsWithDup(vector<int> &nums)
    {
        vector<vector<int>> ans;
        set<vector<int>> res;
        vector<int> ds;
        fun(nums, 0, ds, res);
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
    printAns(ans);
    return 0;
}