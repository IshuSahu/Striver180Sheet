/*
Approach:

Build histogram column-wise:
For each row, build an array height[] of size m, where:
- height[j] is the number of consecutive 1s from row 0 up to current row at column j.
- For each height[] array (one per row), compute the maximum rectangle area in a histogram using a stack.

for input:
3 3
1 0 0
0 1 1
1 1 1
Row 0: [1 0 0]
Row 1: [0 1 1] → becomes [0 1 1]
Row 2: [1 1 1] → becomes [1 2 2]

*/

#include <bits/stdc++.h>
using namespace std;

int largestRectangleArea(vector<int> &heights)
{
    stack<int> st;
    heights.push_back(0);
    int maxArea = 0;

    for (int i = 0; i < heights.size(); ++i)
    {
        /*
        When the current bar is shorter than the one on top of the stack:
        Pop from the stack — you've found the right boundary of a rectangle.
        The popped height is the rectangle's height.
        The width is computed using the current index and the new top of stack (which is the left boundary).
        */
        while (!st.empty() && heights[i] < heights[st.top()])
        {
            int h = heights[st.top()];
            st.pop();
            int width = st.empty() ? i : (i - st.top() - 1);
            maxArea = max(maxArea, h * width);
        }
        st.push(i);
    }
    heights.pop_back();
    return maxArea;
}

int maximalRectangle(vector<vector<int>> &matrix)
{
    if (matrix.empty())
        return 0;
    int n = matrix.size();    // Rows
    int m = matrix[0].size(); // Columns

    vector<int> height(m, 0);
    int maxArea = 0;

    for (int i = 0; i < n; ++i)
    {
        // Build histogram
        for (int j = 0; j < m; ++j)
        {
            if (matrix[i][j] == 1)
                height[j] += 1;
            else
                height[j] = 0;
        }

        maxArea = max(maxArea, largestRectangleArea(height));
    }

    return maxArea;
}
/*
| Aspect    | Complexity |
| --------- | ---------- |
| **Time**  | O(n * m)   |
| **Space** | O(m)       |
*/
int main()
{
    int n, m;
    cin >> n >> m;

    vector<vector<int>> matrix(n, vector<int>(m));

    for (int i = n - 1; i >= 0; --i)
    {
        for (int j = 0; j < m; ++j)
        {
            cin >> matrix[i][j];
        }
    }

    cout << maximalRectangle(matrix) << endl;
    return 0;
}
