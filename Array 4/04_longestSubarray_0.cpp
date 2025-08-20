#include <bits/stdc++.h>
using namespace std;
// time complexity O(n);
int solve(vector<int> &a)
{
    int maxLen = 0;
    unordered_map<int, int> sumIndexMap;
    int sum = 0;

    for (int i = 0; i < a.size(); i++)
    {
        sum += a[i];

        if (sum == 0)
        {
            // cout << sum << a[i] << endl;
            maxLen = i + 1;
        }
        else if (sumIndexMap.find(sum) != sumIndexMap.end())
        {
            maxLen = max(maxLen, i - sumIndexMap[sum]);
        }
        else
        {
            sumIndexMap[sum] = i;
        }
    }

    return maxLen;
}

int main()
{
    vector<int> a = {1, -1, 2, -2, 3};
    cout << solve(a) << endl;

    return 0;
}
