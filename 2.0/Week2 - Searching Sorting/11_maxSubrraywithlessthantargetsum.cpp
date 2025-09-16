/*
Given an array of positive integers arr[] of size n, and an integer k. The task is to find the maximum subarray size such that all subarrays of that size have sum less than or equals to k.
*/
#include <bits/stdc++.h>
using namespace std;

int maxSubarraySize(vector<int> &arr, int k)
{
    int n = arr.size();
    int ans = -1;
    for (int i = 1; i <= n; i++)
    {
        int maxSum = INT_MIN;
        for (int j = 0; j <= n - i; j++)
        {
            int sum = 0;
            for (int l = j; l < j + i; l++)
            {
                sum += arr[l];
            }

            maxSum = max(maxSum, sum);
        }
        if (maxSum <= k)
        {
            ans = max(ans, i);
        }
    }

    return ans;
}

/* INTUATION
1. Monotonic Property (Why Binary Search?)
If subarray size m is valid (all subarrays ≤ k), then all smaller sizes are also valid.
If subarray size m is invalid (some subarray > k), then all larger sizes are also invalid.
*/
int maxSubarraySize2(vector<int> &arr, int k)
{
    int n = arr.size();
    int low = 1, high = n;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        int sum = 0, maxSum = INT_MIN;

        for (int i = 0; i < n; i++)
        {
            sum += arr[i];
            if (i >= mid)
                sum -= arr[i - mid];
            if (i >= mid - 1)
                maxSum = max(maxSum, sum);
        }

        if (maxSum <= k)
            low = mid + 1;
        else
            high = mid - 1;
    }

    if (high == 0)
        return -1;
    return high;
}

/*
We need the largest subarray length where every subarray sum ≤ k.
If some subarray of length L has sum > k, then L is invalid.
So, find the smallest length (minLen) that breaks the rule (sum > k).
Answer = minLen - 1.
If even length 1 fails (some element > k), return -1.

Sliding window helps quickly find the first invalid length without checking all subarrays.
*/
int maxSubarraySize3(vector<int> &arr, int k) {
    int n = arr.size();
    int start = 0, end = 0, sum = 0;
    int minLen = n + 1;

    while(end < n) {
        sum += arr[end]; 
        end++;

        while(sum > k) {
            minLen = min(minLen, end - start);
            sum -= arr[start]; 
            start++;
        }
    }

    int ans = minLen - 1;  
    if(ans == 0) return -1;
    return ans;
}
int main()
{
    vector<int> arr = {1, 2, 3, 4};
    int k = 8;
    // cout << maxSubarraySize(arr, k) << endl;
    cout << maxSubarraySize3(arr, k) << endl;
    return 0;
}