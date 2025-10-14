#include <bits/stdc++.h>
using namespace std;

int shortestSubarrayBruteForce(vector<int> &nums, int k)
{
    int n = nums.size();
    int minLen = INT_MAX;

    for (int i = 0; i < n; ++i)
    {
        long long sum = 0;
        for (int j = i; j < n; ++j)
        {
            sum += nums[j];
            if (sum >= k)
            {
                minLen = min(minLen, j - i + 1);
                break; // We can break early to avoid unnecessary checks
            }
        }
    }

    return (minLen == INT_MAX) ? -1 : minLen;
}

int shortestSubarray(vector<int>& nums, int k) {
    int n = nums.size();
    vector<long long> prefix(n + 1, 0);

    for (int i = 0; i < n; ++i)
        prefix[i + 1] = prefix[i] + nums[i];

    deque<int> dq;
    int minLen = n + 1;

    for (int i = 0; i <= n; ++i) {
        while (!dq.empty() && prefix[i] - prefix[dq.front()] >= k) {
            minLen = min(minLen, i - dq.front());
            dq.pop_front();
        }
        while (!dq.empty() && prefix[i] <= prefix[dq.back()]) {
            dq.pop_back();
        }
        dq.push_back(i);
    }

    return (minLen <= n) ? minLen : -1;
}
// | Metric | Complexity |
// | ------ | ---------- |
// | Time   | **O(n)**   |
// | Space  | **O(n)**   |

int main()
{
    vector<int> nums = {2, -1, 2, 2, 3};
    int k = 3;
    cout << "Shortest Subarray Length = " << shortestSubarrayBruteForce(nums, k) << endl;
    return 0;
}
