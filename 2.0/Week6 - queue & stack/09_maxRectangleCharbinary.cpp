// same as problem 3 just change with char of integer array
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int largestRectangleArea(vector<int> &heights)
    {
        stack<int> st;
        heights.push_back(0);
        int maxArea = 0;
        /*
        When the current bar is shorter than the one on top of the stack:
        Pop from the stack — you've found the right boundary of a rectangle.
        The popped height is the rectangle's height.
        The width is computed using the current index and the new top of stack (which is the left boundary).
        */
        for (int i = 0; i < heights.size(); ++i)
        {
            while (!st.empty() && heights[i] < heights[st.top()])
            {
                int h = heights[st.top()];
                st.pop();
                int width = st.empty() ? i : i - st.top() - 1;
                maxArea = max(maxArea, h * width);
            }
            st.push(i);
        }

        heights.pop_back();
        return maxArea;
    }

    int maximalRectangle(vector<vector<char>> &matrix)
    {
        if (matrix.empty())
            return 0;

        int rows = matrix.size();
        int cols = matrix[0].size();
        vector<int> height(cols, 0);
        int maxRect = 0;

        for (int i = 0; i < rows; ++i)
        {
            for (int j = 0; j < cols; ++j)
            {
                if (matrix[i][j] == '1')
                {
                    height[j] += 1;
                }
                else
                {
                    height[j] = 0;
                }
            }
            maxRect = max(maxRect, largestRectangleArea(height));
        }

        return maxRect;
    }
};

int main()
{
    Solution sol;

    vector<vector<char>> matrix = {
        {'1', '0', '1', '0', '0'},
        {'1', '0', '1', '1', '1'},
        {'1', '1', '1', '1', '1'},
        {'1', '0', '0', '1', '0'}};

    int result = sol.maximalRectangle(matrix);
    cout << "Maximal Rectangle Area = " << result << endl;

    return 0;
}
