#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    void NextSmaller(vector<int> &nums, vector<int> &NS)
    {
        int n = nums.size();
        stack<int> st;
        for (int i = n - 1; i >= 0; i--)
        {
            while (!st.empty() && nums[st.top()] >= nums[i])
            {
                st.pop();
            }
            if (!st.empty())
            {
                NS[i] = st.top(); // Store the index of the next smaller element
            }

            st.push(i);
        }
        for (int i = 0; i < n; i++)
        {
            cout << NS[i] << " ";
        }
        cout << endl;
    }

    void prevSmaller(vector<int> &nums, vector<int> &PS)
    {
        int n = nums.size();
        stack<int> st;
        for (int i = 0; i < n; i++)
        {
            while (!st.empty() && nums[st.top()] >= nums[i])
            {
                st.pop();
            }
            if (!st.empty())
            {
                PS[i] = st.top();
            }
            st.push(i);
        }
        for (int i = 0; i < n; i++)
        {
            cout << PS[i] << " ";
        }
        cout << endl;
    }

    int largestRectangleArea(vector<int> &heights)
    {
        int maxA = 0;
        int n = heights.size();
        vector<int> NS(n, n);
        vector<int> PS(n, -1);

        NextSmaller(heights, NS);
        prevSmaller(heights, PS);

        for (int i = 0; i < n; i++)
        {
            int curMax = (NS[i] - PS[i] - 1) * heights[i];
            // cout << NS[i] << " : " << PS[i] << "=> val: "<<curMax<<endl;
            maxA = max(maxA, curMax);
        }

        return maxA;
    }
};

int main()
{
    vector<int> heights = {2, 1, 5, 6, 2, 3, 1};
    Solution obj;
    cout << "The largest area in the histogram is  " << obj.largestRectangleArea(heights) << endl;
    return 0;
}
