#include <bits/stdc++.h>

using namespace std;
class Solution
{
public:
    vector<int> nextGreaterElementsarr(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> ans(n, -1); // Initialize the answer array with -1
        for (int i = 0; i < n; i++)
        {
            for (int j = 1; j < n; j++)
            {
                if (nums[i] < nums[(i + j) % n])
                {
                    ans[i] = nums[(i + j) % n];
                    break;
                }
            }
        }
        return ans;
    }

    vector<int> nextSmallerElements(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> ans(n, -1);
        stack<int> st;
        for (int i = 0; i < n; i++)
        {
            while (!st.empty() && st.top() > nums[i])
            {
                st.pop();
            }
            if (!st.empty())
            {
                ans[i] = st.top();
            }
            st.push(nums[i]);
        }
        return ans;
    }
};
int main()
{
    Solution s;
    vector<int> v{4, 5, 2, 10, 8};
    // vector<int> res = s.nextGreaterElementsarr(v);
    vector<int> res = s.nextSmallerElements(v);
    cout << "The next greater elements are" << endl;
    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i] << " ";
    }
    return 0;
}