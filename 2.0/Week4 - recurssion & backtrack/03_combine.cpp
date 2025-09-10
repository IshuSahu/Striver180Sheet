#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    void combineHelper(int start, int n, int k, vector<int> &current, vector<vector<int>> &result)
    {
        if (current.size() == k)
        {
            result.push_back(current);
            return;
        }

        for (int i = start; i <= n; ++i)
        {
            current.push_back(i);
            combineHelper(i + 1, n, k, current, result);
            current.pop_back(); // Backtrack
        }
    }

    vector<vector<int>> combine(int n, int k)
    {
        vector<vector<int>> result;
        vector<int> current;
        combineHelper(1, n, k, current, result);
        return result;
    }
};
int main()
{
    Solution os;
    int n = 9, k = 3;
    vector<vector<int>> result = os.combine(n, k);
    for (int i = 0; i < result.size(); i++)
    {
        cout << "[";
        for (int j = 0; j < k; j++)
        {
            cout << result[i][j] << " ";
        }
        cout << "], ";
    }
    return 0;
}
