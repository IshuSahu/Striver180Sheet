// #include <iostream>
// #include <vector>

// using namespace std;
// class Solution
// {
// private:
//     void solve(vector<int> nums, vector<vector<int>> &ans, int index)
//     {
//         // base case
//         if (index >= nums.size())
//         {
//             ans.push_back(nums);
//             return;
//         }

//         for (int i = index; i < nums.size(); i++)
//         {
//             swap(nums[index], nums[i]);
//             solve(nums, ans, index + 1);
//             // backtrack
//             swap(nums[index], nums[i]); // It will go bak to previous index;
//         }
//     }

// public:
//     vector<vector<int>> permute(vector<int> &nums)
//     {
//         vector<vector<int>> ans;
//         int index = 0;
//         solve(nums, ans, index);
//         return ans;
//     }
// };

// int main()
// {
//     vector<int> nums = {1, 2, 3};
//     Solution solution;
//     vector<vector<int>> permutations = solution.permute(nums);

//     // Print the permutations
//     for (const auto &permutation : permutations)
//     {
//         for (int num : permutation)
//         {
//             cout << num << " ";
//         }
//         cout << endl;
//     }

//     return 0;
// }

// permutaiton of string:
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
private:
    void solve(string &s, int index, vector<string> &res)
    {
        if (index == s.size())
        {
            res.push_back(s);
            return;
        }
        for (int i = index; i < s.size(); i++)
        {
            swap(s[i], s[index]);
            solve(s, index + 1, res);
            // backtrack
            swap(s[i], s[index]);
        }
    }

public:
    vector<string> digitPermutations(string s)
    {
        vector<string> ans;

        if (s.length() == 0)
        {
            return ans;
        }
        solve(s, 0, ans);
        return ans;
    }
};

int main()
{
    Solution solution;
    string digits = "123";

    vector<string> permutations = solution.digitPermutations(digits);

    // Display the generated permutations
    cout << "Permutations for " << digits << ": ";
    for (const string &permutation : permutations)
    {
        cout << permutation << " ";
    }
    cout << endl;

    return 0;
}