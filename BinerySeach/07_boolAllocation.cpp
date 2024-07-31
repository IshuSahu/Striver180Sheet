

#include <bits/stdc++.h>
using namespace std;

bool allocationPosible(int barrier, vector<int> &arr, int stu)
{
    int allocatestu = 1;
    int pages = 0;

    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] > barrier)
            return false;
        if (pages + arr[i] > barrier)
        {
            allocatestu++;
            pages = arr[i];
        }
        else
        {
            pages += arr[i];
        }
    }
    if (allocatestu > stu)
    {
        return false;
    }
    else
    {
        return true;
    }
}

int findPages(vector<int> &arr, int n, int m)
{
    // book allocation impossible:
    if (m > n)
        return -1;

    int low = *min_element(arr.begin(), arr.end());
    int high = accumulate(arr.begin(), arr.end(), 0);
    int res = -1;
    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (allocationPosible(mid, arr, m))
        {
            res = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return low;
}

int main()
{
    vector<int> arr = {25, 46, 28, 49, 24};
    int n = 5;
    int m = 4;
    int ans = findPages(arr, n, m);
    cout << "The answer is: " << ans << "\n";
    return 0;
}
