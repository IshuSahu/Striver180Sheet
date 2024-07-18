#include <iostream>
#include <vector>
using namespace std;

class Solution
{
private:
    // Here Output Is Answer array
    void solve(vector<int> nums, vector<int> output, int index, vector<vector<int>> &ans)
    {
        // base case
        if (index >= nums.size())
        {
            ans.push_back(output);
            return;
        }
        // // exclude;
        // solve(nums, output, index + 1, ans);
        // // include
        // int element = nums[index];
        // output.push_back(element);
        // solve(nums, output, index + 1, ans);

        // or

        // include
        int element = nums[index];
        output.push_back(element);
        solve(nums, output, index + 1, ans);
        output.pop_back();
        // exclude;
        solve(nums, output, index + 1, ans);
    }

public:
    vector<vector<int>> subsets(vector<int> &nums)
    {
        vector<vector<int>> ans;
        vector<int> output;

        int index = 0;
        solve(nums, output, index, ans);
        return ans;
    }
};

int main()
{
    Solution solution;
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> subsets = solution.subsets(nums);

    // Print subsets
    for (const auto &subset : subsets)
    {
        for (int num : subset)
        {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}

// THis is For Subsequence of String
// #include <bits/stdc++.h>
// using namespace std;
// void solve(string str, string output,  int index, vector<string>& ans){
// 	// base case
// 	if(index >=str.length()){
// 		if(output.length()>0){
// 			ans.push_back(output);
// 		}
// 		return;
// 	}
// 	// Exclude
// 	solve(str, output, index+1, ans);

// 	// Include
// 	char element = str[index];
// 	output.push_back(element);
// 	solve(str, output, index+1, ans);
// }

// vector<string> subsequences(string str){

// 	vector<string> ans;
// 	string output="";
// 	int index=0;
// 	solve(str, output, index, ans);
// 	return ans;

// }
