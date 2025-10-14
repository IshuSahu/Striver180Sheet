#include<bits/stdc++.h>

using namespace std;

class Solution
{
public:
    // Binary search to count soldiers in a row
    int countSoldiers(const vector<int> &row)
    {
        int low = 0, high = row.size();
        while (low < high)
        {
            int mid = low + (high - low) / 2;
            if (row[mid] == 1)
                low = mid + 1;
            else
                high = mid; // imp
        }
        return low; // number of 1's (soldiers) (it result first index of 0)
    }

    vector<int> kWeakestRowsBrut(vector<vector<int>> &mat, int k)
    {
        vector<pair<int, int>> strength; // pair of (soldier count, row index)

        for (int i = 0; i < mat.size(); ++i)
        {
            int soldiers = countSoldiers(mat[i]);
            strength.push_back({soldiers, i});
        }

        // Sort by soldier count, then by row index
        sort(strength.begin(), strength.end());

        vector<int> result;
        for (int i = 0; i < k; ++i)
            result.push_back(strength[i].second);

        return result;
    }

    vector<int> kWeakestRows(vector<vector<int>> &mat, int k)
    {
        priority_queue<pair<int, int>> maxHeap;

        for (int i = 0; i < mat.size(); ++i)
        {
            int soldiers = countSoldiers(mat[i]);
            maxHeap.push({soldiers, i});
            if (maxHeap.size() > k)
            {
                maxHeap.pop(); 
            }
        }

        // Extract results from the heap (in reverse order)
        vector<int> result(k);
        for (int i = k - 1; i >= 0; --i)
        {
            result[i] = maxHeap.top().second;
            maxHeap.pop();
        }

        return result;
    }
};

// Sample usage
int main()
{
    Solution sol;
    vector<vector<int>> mat = {
        {1, 1, 0, 0, 0},
        {1, 1, 1, 1, 0},
        {1, 0, 0, 0, 0},
        {1, 1, 0, 0, 0},
        {1, 1, 1, 1, 1}};
    int k = 3;
    vector<int> result = sol.kWeakestRows(mat, k);

    for (int idx : result)
    {
        cout << idx << " ";
    }
    cout << endl;

    return 0;
}
