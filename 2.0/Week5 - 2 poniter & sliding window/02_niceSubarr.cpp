#include <iostream>
#include <vector>

using namespace std;

int Count(vector<int> &nums, int k)
{
    int count = 0;
    int n = nums.size();

    for (int i = 0; i < n; i++)
    {
        int oddCount = 0;

        for (int j = i; j < n; j++)
        {
            if (nums[j] % 2 != 0)
            {
                oddCount++;
            }

            if (oddCount == k)
            {
                count++;
            }
        }
    }

    return count;
}

int atMostKOdd(const vector<int> &nums, int k)
{
    int count = 0;
    int left = 0, oddCount = 0;

    for (int i = 0; i < nums.size(); ++i)
    {
        if (nums[i] % 2 != 0)
        {
            oddCount++;
        }

        while (oddCount > k)
        {
            if (nums[left] % 2 != 0)
            {
                oddCount--;
            }
            left++;
        }

        count += i - left + 1; // add count of no. of subarrays
    }

    return count;
}

int Count(vector<int> &nums, int k)
{
    return atMostKOdd(nums, k) - atMostKOdd(nums, k - 1);
}

int main()
{
    vector<int> nums = {1, 1, 2, 1, 1};
    int k = 3;
    cout << "Number of nice subarrays: " << Count(nums, k) << endl;
    return 0;
}
