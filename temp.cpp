#include <bits/stdc++.h>

using namespace std;

int findnonDuplicate(int *arr, int n)
{
    // PROBLEM HERE
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans = ans ^ arr[i];
    }
    return ans;
}

int main()
{
    int arr[] = {1, 1, 2, 2, 3, 3, 4, 5, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    int res = findnonDuplicate(arr, n);
    cout << res << endl;
    return 0;
}
