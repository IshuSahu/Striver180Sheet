/*
Input: N=3,arr[]= {3,1,2}

Output: 0,1,2,3,3,4,5,6

Explanation: We have to find all the subset’s sum and print them.in this case the generated subsets are [ [], [1], [2], [2,1], [3], [3,1], [3,2]. [3,2,1],so the sums we get will be  0,1,2,3,3,4,5,6

*/

#include <bits/stdc++.h>

using namespace std;
class Solution
{
public:
    void helper(vector<int> &arr, int n, vector<int> &ans, int ind, int sum)
    {
        if (ind == n)
        {
            ans.push_back(sum);
            return;
        }
        // Include
        helper(arr, n, ans, ind + 1, sum + arr[ind]);
        // Exclude
        helper(arr, n, ans, ind + 1, sum);
    }
    vector<int> subsetSums(vector<int> &arr, int n)
    {
        vector<int> ans;
        int ind = 0;
        helper(arr, n, ans, ind, 0);
        sort(ans.begin(), ans.end());
        return ans;
    }

    int subarraySum(vector<int> &arr)
    {
        int sum = 0;
        vector<int> ans;
        int n = arr.size();
        int ind = 0;
        helper(arr, n, ans, ind, sum);
        sum = 0;
        for (int i = 0; i < ans.size(); i++)
        {
            sum += ans[i];
        }
        return sum;
    }
};
int main()
{
    vector<int> arr{1, 2, 3};
    Solution ob;
    vector<int> ans = ob.subsetSums(arr, arr.size());
    sort(ans.begin(), ans.end());
    cout << "The sum of each subset is " << endl;
    for (auto sum : ans)
    {
        cout << sum << " ";
    }
    cout << endl;
    int res= ob.subarraySum(arr);
    cout<<res<<endl;

    return 0;
}