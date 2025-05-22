#include <bits/stdc++.h>

using namespace std;
vector<vector<int>> threeSum(vector<int> &nums)
{
    int n = nums.size();
    set<vector<int>> h_set;

    for (int i = 0; i < n; i++)
    {
        set<int> st;
        for (int j = i + 1; j < n; j++)
        {
            int target = 0 - (nums[i] + nums[j]);
            if (st.find(target) != st.end())
            {
                vector<int> temp = {nums[i], nums[j], target};
                sort(temp.begin(), temp.end());
                h_set.insert(temp);
            }
            st.insert(nums[j]);
        }
    }

    vector<vector<int>> ans(h_set.begin(), h_set.end());
    return ans;
}
int main()
{

    return 0;
}