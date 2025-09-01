#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        int m = matrix.size();
        int n = matrix[0].size();
        int low = 0, high = (m * n) - 1;

        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            int row = mid / n;
            int col = mid % n;
            cout<<row<<
            if (matrix[row][col] == target)
            {
                return true;
            }
            else if (matrix[row][col] > target)
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }

        return false;
    }
};

int main()
{
    Solution solution;

    vector<vector<int>> matrix1 = {
        {1, 4},
        {2, 5}};
    int target1 = 2;

    bool result1 = solution.searchMatrix(matrix1, target1);
    cout << "Result for target " << target1 << " in matrix1: " << (result1 ? "Found" : "Not Found") << endl;

    return 0;
}
