#include <bits/stdc++.h>
using namespace std;

int sumOfMinAndMaxBrut(vector<int> arr)
{
    int k = 4;
    int n = arr.size();
    int ans = 0;
    for (int i = 0; i < n - (k - 1); i++)
    {
        int maxval = INT_MIN;
        int minval = INT_MAX;
        for (int j = i; j < i + k; j++)
        {
            maxval = max(maxval, arr[j]);
            minval = min(minval, arr[j]);
        }
        ans += (maxval + minval);
    }
    return ans;
}

int sumOfMinAndMax(vector<int> &arr, int k)
{
    int n = arr.size();
    deque<int> maxDeque, minDeque;
    int sum = 0;

    for (int i = 0; i < n; ++i)
    {
        // Remove elements out of current window from front
        if (!maxDeque.empty() && maxDeque.front() <= i - k)
            maxDeque.pop_front();
        if (!minDeque.empty() && minDeque.front() <= i - k)
            minDeque.pop_front();

        // Remove smaller elements (for maxDeque)
        while (!maxDeque.empty() && arr[maxDeque.back()] <= arr[i])
            maxDeque.pop_back();
        // Remove larger elements (for minDeque)
        while (!minDeque.empty() && arr[minDeque.back()] >= arr[i])
            minDeque.pop_back();

        // Add current index to both deques
        maxDeque.push_back(i);
        minDeque.push_back(i);

        // Window formed, add to result
        if (i >= k - 1)
            sum += arr[maxDeque.front()] + arr[minDeque.front()];
    }

    return sum;
}

/*
| Feature             | Brute Force | Optimized (Deque) |
| ------------------- | ----------- | ----------------- |
| Time Complexity     | O(n * k)    | **O(n)** ✅        |
| Space Complexity    | O(1)        | O(k)              |
| Handles Large Input | ❌ Slow      | ✅ Fast            |

*/
int main()
{
    vector<int> arr = {2, 5, -1, 7, -3, -1, -2};
    int k = 4;
    cout << sumOfMinAndMax(arr, k) << endl; // Output: 18
    return 0;
}
