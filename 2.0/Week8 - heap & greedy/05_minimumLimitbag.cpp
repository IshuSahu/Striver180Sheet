/*
Problem Statement: In Simple Terms
You are given:
    An array nums — each element represents a bag of balls.
    For example: nums = [9] means one bag containing 9 balls.
    An integer maxOperations — the maximum number of times you are allowed to split a bag.
What can you do?
You can perform the following operation at most maxOperations times:
    Take one bag and split it into two new bags, in any way you like, as long as both bags have at least 1 ball.
    Example: a bag of 5 balls can be split as:
    1 and 4
    2 and 3
    etc.
Your Goal:
After splitting bags (up to maxOperations times), you will have multiple bags.
👉 You want to make the largest bag (after splitting) as small as possible.
This size is called your penalty.
*/
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
/*Optimal Binary Search + Greedy*/
    bool isPossible(vector<int> &nums, int maxOperations, int penalty)
    {
        int operations = 0;
        for (int balls : nums)
        {
            // Number of splits needed for this bag
            operations += (balls - 1) / penalty;
        }
        return operations <= maxOperations;
    }

    int minimumSize(vector<int> &nums, int maxOperations)
    {
        int left = 1, right = *max_element(nums.begin(), nums.end());
        int result = right;

        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (isPossible(nums, maxOperations, mid))
            {
                result = mid; // try smaller penalty
                right = mid - 1;
            }
            else
            {
                left = mid + 1; // try larger penalty
            }
        }

        return result;
    }
};
