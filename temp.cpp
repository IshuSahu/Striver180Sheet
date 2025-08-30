#include <bits/stdc++.h>
using namespace std;

vector<int> findDuplicates(vector<int> &arr)
{
    vector<int> ans;
    int n = arr.size();
    vector<int> hashArr(n + 1, 0);

    for (int i = 0; i < n; i++)
    {
        hashArr[arr[i]]++;
    }

    for (int i = 0; i <= n; i++)
    {
        if (hashArr[i] > 1)
        {
            // cout << hashArr[i] << endl;
            for (int j = 1; j < hashArr[i]; j++)
            {
                ans.push_back(i);
            }
        }
    }
    return ans;
}

int main()
{
    vector<int> arr = {3, 2, 3};
    vector<int> res = findDuplicates(arr);
    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i] << " ";
    }
    return 0;
}
