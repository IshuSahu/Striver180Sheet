#include <iostream>
#include <vector>

using namespace std;

int sumOfAllSubmatrices(const vector<vector<int>> &mat)
{
    int n = mat.size();
    int totalSum = 0;

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {

            int numSubmatrices = (i + 1) * (j + 1) * (n - i) * (n - j);
            totalSum += mat[i][j] * numSubmatrices;
        }
    }

    return totalSum;
}

int main()
{
    vector<vector<int>> mat = {
        {1, 1},
        {1, 1}};

    int result = sumOfAllSubmatrices(mat);
    cout << "Sum of all submatrices: " << result << endl; // Expected Output: 16

    vector<vector<int>> mat2 = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}};

    result = sumOfAllSubmatrices(mat2);
    cout << "Sum of all submatrices: " << result << endl;

    return 0;
}
