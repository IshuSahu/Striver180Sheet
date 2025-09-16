#include <bits/stdc++.h>

using namespace std;

int kthSmallest(vector<vector<int>> &matrix, int k)
{
    vector<int> ans;
    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix[0].size(); j++)
        {
            ans.push_back(matrix[i][j]);
        }
    }
    sort(ans.begin(), ans.end());
    return ans[k - 1];
}

// Include the functions you provided
int countLessEqual(const vector<vector<int>> &matrix, int target)
{
    int n = matrix.size();
    int count = 0;
    int row = n - 1, col = 0;
    while (row >= 0 && col < n)
    {
        if (matrix[row][col] <= target)
        {
            count += row + 1;
            col++;
        }
        else
        {
            row--;
        }
    }
    return count;
}

int kthSmallestOP(vector<vector<int>> &matrix, int k)
{
    int n = matrix.size();
    int left = matrix[0][0], right = matrix[n - 1][n - 1];
    while (left < right)
    {
        int mid = left + (right - left) / 2; 
        if (countLessEqual(matrix, mid) < k)
        {
            left = mid + 1;
        }
        else
        {
            right = mid; //IMP not to decrement mid!
        }
    }
    return left;
}

int main()
{
    // Example matrix
    vector<vector<int>> matrix = {
        {1, 5, 9},
        {10, 11, 13},
        {12, 13, 15}};
    int k = 8;

    int result = kthSmallestOP(matrix, k);
    cout << "The " << k << "-th smallest element is: " << result << endl;

    return 0;
}
