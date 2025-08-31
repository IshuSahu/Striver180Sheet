#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void segregateEvenOdd(vector<int> &arr)
    {
        sort(arr.begin(), arr.end());
        int low = 0, high = arr.size() - 1;
        while (low < high)
        {
            if (arr[low] % 2 != 0 && arr[high] % 2 == 0)
            {
                swap(arr[low], arr[high]);
            }

            if (arr[low] % 2 == 0)
            {
                low++;
            }
            if (arr[high] % 2 != 0)
            {
                high--;
            }
        }
    }
};

int main()
{
    Solution sol;
    vector<int> arr = {12, 34, 45, 9, 8, 90, 3};
    sol.segregateEvenOdd(arr);

    for (int i : arr)
    {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}
