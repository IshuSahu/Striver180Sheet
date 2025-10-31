#include <bits/stdc++.h>
using namespace std;

vector<int> singleNumberBruteForce(vector<int> &nums)
{
    vector<int> ans;
    int n = nums.size();

    for (int i = 0; i < n; i++)
    {
        int count = 0;
        for (int j = 0; j < n; j++)
        {
            if (nums[i] == nums[j])
                count++;
        }
        if (count == 1)
            ans.push_back(nums[i]);
    }
    return ans;
}
//TC: O(N)

vector<int> singleNumberHashmap(vector<int>& nums) {
    unordered_map<int, int> freq;

    // Count frequency of each element
    for (int num : nums)
        freq[num]++;

    // Collect numbers that appear exactly once
    vector<int> ans;
    for (auto &p : freq) {
        if (p.second == 1)
            ans.push_back(p.first);
    }

    return ans;
}

// Time Complexity: O(N)
// Space O(N) (for hash map)


/**
Using BitWise Operator XOR
⚙️ Steps
- Compute XOR of all numbers → xorAll = num1 ^ num2
- Find a bit that is set (1) in xorAll → this bit differs between num1 and num2
- Divide all numbers into two groups:
    - Group 1: numbers with that bit = 1
    - Group 2: numbers with that bit = 0
XOR numbers in each group → the duplicates cancel out, leaving the two unique numbers.
 */
vector<int> singleNumberOptimized(vector<int> &nums)
{
    int xorAll = 0;
    for (int x : nums)
        xorAll ^= x;

    // Find a set bit (rightmost 1-bit)
    int diffBit = xorAll & -xorAll;

    int a = 0, b = 0;
    for (int x : nums)
    {
        if (x & diffBit)
            a ^= x; // belongs to first group
        else
            b ^= x; // belongs to second group
    }
    return {a, b};
}
/*
TC = O(N)
SC = O(1)
*/
int main()
{
    vector<int> nums = {1, 2, 1, 3, 2, 5}; // Hardcoded sample

    cout << "Input: ";
    for (int x : nums)
        cout << x << " ";
    cout << "\n";

    vector<int> ans = singleNumberBruteForce(nums);
    for (int x : ans)
        cout << x << " ";
    cout << "\n";
    return 0;
}
