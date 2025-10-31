#include <bits/stdc++.h>
using namespace std;

long long bruteForceSum(vector<int> &arr)
{
    int n = arr.size();
    long long sum = 0;

    for (int i = 0; i < n; i++)
    {
        int currOR = 0;
        for (int j = i; j < n; j++)
        {
            currOR |= arr[j];
            sum += currOR;
        }
    }

    return sum;
}

/*
Instead of calculating the OR for every subarray (expensive),
we look at each bit separately and count how many subarrays include it.
Each bit’s total contribution can then be added directly to get the final sum.
*/
long long optimizedSum(vector<int> &a)
{
    int n = a.size();
    long long totalSub = 1LL * n * (n + 1) / 2;
    long long ans = 0;

    for (int bit = 0; bit < 32; bit++)
    {
        long long zeroSub = 0, len = 0;

        for (int i = 0; i < n; i++)
        {
            if ((a[i] & (1 << bit)) == 0)
            {
                len++;
            }
            else
            {
                zeroSub += len * (len + 1) / 2;
                len = 0;
            }
        }
        zeroSub += len * (len + 1) / 2;

        long long withBit = totalSub - zeroSub;
        ans += withBit * (1LL << bit);
    }

    return ans;
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5}; // hardcoded input
    cout << "Array: ";
    for (int x : arr)
        cout << x << " ";
    cout << "\n";

    long long result = bruteForceSum(arr);
    // long long result = optimizedSum(arr);
    cout << "Brute Force Sum of OR of all subarrays = " << result << "\n";
    return 0;
}
