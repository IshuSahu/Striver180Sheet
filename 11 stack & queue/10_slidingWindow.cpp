#include <bits/stdc++.h>

using namespace std;

int findMax(int st, vector<int> &nums, int k)
{
    int Max = nums[st];
    for (int i = st + 1; i < st + k; i++)
    {
        Max = max(Max, nums[i]);
    }
    return Max;
}

vector<int> maxSlidingWindow(vector<int> &nums, int k)
{
    vector<int> ans;
    for (int i = 0; i < nums.size(); i++)
    {
        if (i + k - 1 < nums.size())
        {
            ans.push_back(findMax(i, nums, k));
        }
        else
        {
            ans.push_back(nums[i]);
        }
    }
    return ans;
}

int main()
{
    vector<int> arr{2, 3, 0, 1, 3, 1, 6};
    int k = 3;
    vector<int> ans = maxSlidingWindow(arr, k);
    cout << "Maximum element ";
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";
    return 0;
}
