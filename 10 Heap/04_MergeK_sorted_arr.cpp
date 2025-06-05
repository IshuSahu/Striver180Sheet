#include <bits/stdc++.h>
using namespace std;

vector<int> mergeKArrays(const vector<vector<int>> &arr)
{
    vector<int> res;
    for (const auto &vec : arr)
    {
        for (int val : vec)
            res.push_back(val);
    }
    sort(res.begin(), res.end());
    return res;
}
vector<int> mergeKArrays2(const vector<vector<int>> &arr)
{
    // Min-heap: {value, array index, element index}
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> minHeap;

    // Push first element of each array
    for (int i = 0; i < arr.size(); ++i)
    {
        if (!arr[i].empty())
        {
            minHeap.push({arr[i][0], i, 0});
        }
    }

    vector<int> result;

    while (!minHeap.empty())
    {
        tuple<int, int, int> top = minHeap.top();
        int val = get<0>(top);
        int i = get<1>(top);
        int j = get<2>(top);
        minHeap.pop();
        result.push_back(val);

        // If the array has more elements, push the next one
        if (j + 1 < arr[i].size())
        {
            minHeap.push({arr[i][j + 1], i, j + 1});
        }
    }

    return result;
}
int main()
{
    vector<vector<int>> arr = {{2, 6, 12, 34},
                               {1, 9, 20, 1000},
                               {23, 34, 90, 2000}};
    vector<int> res = mergeKArrays2(arr);
    for (int val : res)
    {
        cout << val << " ";
    }
    return 0;
}
