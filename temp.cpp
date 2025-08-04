#include <bits/stdc++.h>

using namespace std;
vector<vector<int>> mergeOverlappingIntervals1(vector<vector<int>> arr)
{
    int n = arr.size();
    vector<vector<int>> ans;
    sort(arr.begin(), arr.end());
    for (int i = 0; i < n; i++)
    {

        if (ans.empty() || arr[i][0] > ans.back()[1])
        {
            ans.push_back(arr[i]);
        }
        else
        {
            ans.back()[1] = max(arr[i][1], ans.back()[1]);
        }
    }
    return ans;
}

int main()
{
    vector<vector<int>> arr = {{1, 3}, {2, 6}, {8, 10}, {11, 13}};
    // vector<vector<int>> ans = mergeOverlappingIntervals(arr);
    vector<vector<int>> ans = mergeOverlappingIntervals1(arr);
    cout << "The merged intervals are: " << "\n";
    for (auto it : ans)
    {
        cout << "[" << it[0] << ", " << it[1] << "] ";
    }
    cout << endl;
    return 0;
}