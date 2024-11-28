#include <bits/stdc++.h>

using namespace std;

int main()
{
    vector<int> arr = {3, 4, 5, 3, 2, 1, 4};
    int n = arr.size();
    int target = 8;
    set<vector<int>> res;
    set<long long> st;
    sort(arr.begin(), arr.end());
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            int T = target - (arr[i] + arr[j]);
            if (st.find(T) != st.end())
            {
                vector<int> tem = {arr[i], arr[j], T};
                sort(tem.begin(), tem.end());
                res.insert(tem);
            }
            st.insert(arr[j]);
        }
    }
     for (auto it : res)
    {
        cout << "[";
        for (auto ele : it)
        {
            cout << ele << " ";
        }
        cout << "] ";
    }

    return 0;
}
