#include <bits/stdc++.h>

using namespace std;
int longestOnesBruteForce(vector<int> &nums, int k)
{
    int maxLen = 0;
    int n = nums.size();

    for (int i = 0; i < n; ++i)
    {
        int zeros = 0;
        for (int j = i; j < n; ++j)
        {
            if (nums[j] == 0)
            {
                zeros++;
            }
            if (zeros > k)
                break;
            maxLen = max(maxLen, j - i + 1);
        }
    }

    return maxLen;
}

int longestOnes(vector<int> &nums, int k)
{
            int left = 0, right = 0, zeros = 0, maxLen = 0;
            int n = nums.size();

            for (right = 0; right < n; ++right)
            {
                if (nums[right] == 0)
                {
                    zeros++;
                }

                while (zeros > k)
                {
                    if (nums[left] == 0)
                    {
                        zeros--;
                    }
                    left++;
                }

                maxLen = max(maxLen, right - left + 1);
            }

            return maxLen;
}

int main()
{
    vector<int> nums = {1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0};
    int k = 2;

    cout << "Brute Force: " << longestOnesBruteForce(nums, k) << endl;
    cout << "Optimal: " << longestOnes(nums, k) << endl;
    return 0;
}