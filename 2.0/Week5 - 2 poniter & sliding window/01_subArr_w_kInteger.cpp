// Subarray with k different integers | 2 Pointers and Sliding Window
#include <bits/stdc++.h>

using namespace std;
// O(n2)
int TotalPairs(vector<int> nums, int k)
{
    int count = 0;
    int n = nums.size();
    for (int i = 0; i < n; i++)
    {
        unordered_map<int, int> mpp;
        for (int j = i; j < n; j++)
        {
            mpp[nums[j]]++;
            if (mpp.size() == k)
                count++;
            else if (mpp.size() > k)
                break;
        }
    }
    return count;
}

int helper(vector<int> &nums, int k)
{
    int left = 0, cnt = 0;
    unordered_map<int, int> mpp;

    for (int i = 0; i < nums.size(); ++i)
    {
        mpp[nums[i]]++;

        while (mpp.size() > k)
        {
            mpp[nums[left]]--;
            if (mpp[nums[left]] == 0)
            {
                mpp.erase(nums[left]);
            }
            left++;
        }

        cnt += i - left + 1;
        // cout << cnt<<endl;
    }

    return cnt;
}

int TotalPairs2(vector<int> nums, int k)
{
    return helper(nums, k) - helper(nums, k - 1);
}

int main()
{
    vector<int> arr = {1, 2, 1, 4, 3};
    // cout << TotalPairs(arr, 2) << endl;
    cout << TotalPairs2(arr, 2) << endl;
    return 0;
}