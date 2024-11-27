#include <bits/stdc++.h>

using namespace std;
bool B_search(vector<int> arr, int T)
{
    int low = 0;
    int high = arr.size() - 1;  
    while (low <=high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] == T)
            return true;
        else if (arr[mid] < T)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    return false;
}
int main()
{
    vector<vector<int>> arr = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}, {11, 12, 13}};

    int m = arr.size();
    int n = arr[0].size();
    int T = 9;
    bool res = 0;
    for (int i = 0; i < m; i++)
    {
        if (arr[i][0] <= T && T <= arr[i][n - 1])
        {
            res = B_search(arr[i], T);
        }
    }
    if (res)
    {
        cout << "Found";
    }
    else
    {
        cout << "Not Found";
    }

    return 0;
}