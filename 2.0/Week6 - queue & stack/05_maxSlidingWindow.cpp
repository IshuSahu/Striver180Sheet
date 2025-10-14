#include <bits/stdc++.h>

using namespace std;
class Solution
{
public:
    vector<int> maxSlidingWindowBrut(vector<int> &arr, int k)
    {
        int n = arr.size();
        vector<int> ans;
        for (int i = 0; i < n - (k - 1); i++)
        {
            int maxval = arr[i];
            for (int j = i; j < i + k; j++)
            {
                maxval = max(maxval, arr[j]);
            }
            ans.push_back(maxval);
        }
        return ans;
    }

    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        deque<int> dq; // Stores indices
        vector<int> result;

        for (int i = 0; i < nums.size(); i++)
        {
            // 1. Remove indices out of window
            if (!dq.empty() && dq.front() == i - k)
                dq.pop_front();

            // 2. Remove all elements smaller than current
            while (!dq.empty() && nums[dq.back()] < nums[i])
                dq.pop_back();

            // 3. Add current index
            dq.push_back(i);

            // 4. Store result starting from when first window is complete
            if (i >= k - 1)
                result.push_back(nums[dq.front()]);
        }

        return result;
    }
};
/*
Time	O(n)
Space	O(k)
*/

int main()
{

    return 0;
}