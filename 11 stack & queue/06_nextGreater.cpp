#include <bits/stdc++.h>

using namespace std;
class Solution
{
public:
    vector<int> nextGreaterElementsarr(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> ans(n, -1);
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

    vector<int> nextGreaterElements(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> ans(n, -1);
        stack<int> st;
        for (int i = 2 * n - 1; i >= 0; i--)
        {
            while (!st.empty() && st.top() <= nums[i % n])
            {
                st.pop();
            }

            if (i < n)
            {
                if (!st.empty())
                    ans[i] = st.top();
            }
            st.push(nums[i % n]);
        }
        return ans;
    }
};
int main()
{
    Solution s;
    vector<int> v{5, 7, 1, 2, 6, 0};
    // vector<int> res = s.nextGreaterElementsarr(v);
    vector<int> res = s.nextGreaterElements(v);
    cout << "The next greater elements are" << endl;
    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i] << " ";
    }
    return 0;
}

/*
✅ Amortized Complexity
Outer loop = 2n iterations → O(n).
Stack operations = n pushes + n pops → O(n).

So total = O(n), not O(n²).

🔎 What is Amortized Complexity?

Amortized complexity is a way of analyzing algorithms where an operation might sometimes be expensive (cost a lot of time), but when you look at a sequence of many operations, the average cost per operation stays small.
*/

