#include <bits/stdc++.h>

using namespace std;
// int numSubarraysWithSum(vector<int> &nums, int goal)
// {
//     int count = 0;
//     int n = nums.size();

//     for (int i = 0; i < n; ++i)
//     {
//         int sum = 0;
//         for (int j = i; j < n; ++j)
//         {
//             sum += nums[j];
//             if (sum == goal)
//                 count++;
//         }
//     }

//     return count;
// }

int atMost(vector<int> &nums, int goal)
{
    if (goal < 0)
        return 0;

    int left = 0, sum = 0, count = 0;

    for (int right = 0; right < nums.size(); ++right)
    {
        sum += nums[right];

        while (sum > goal)
        {
            sum -= nums[left];
            left++;
        }
        count += (right - left + 1);
    }

    return count;
}

int numSubarraysWithSum(vector<int> &nums, int goal)
{
    return atMost(nums, goal) - atMost(nums, goal - 1);
}

int main()
{
    // Example input
    vector<int> nums = {1, 0, 1, 0, 1};
    int goal = 2;

    int result = numSubarraysWithSum(nums, goal);
    cout << "Number of subarrays with sum " << goal << " = " << result << endl;

    return 0;
}