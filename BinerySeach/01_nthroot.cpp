#include <bits/stdc++.h>

using namespace std;
long long solve(int k, int n)
{
    long long res = 1;
    for (int i = 1; i <= n; i++)
    {
        res = res * k;
    }
    return res;
}
long long NthRoot(int n, int m)
{
    long long ans = -1;
    for (int i = 1; i <= m; i++)
    {
        int temp = solve(i, n);
        if (temp == m)
        {
            return i;
        }
        else if (temp > m)
        {
            return -1;
        }
    }
}
int NthRootBS(int n, int m)
{
    int low = 1;
    int high = m;

    while (low <= high)
    {
        int mid = (low + high) / 2;
        long long ans = solve(mid, n);
        if (ans == m)
            return mid;
        else if (ans > m)
            high = mid - 1;
        else
            low = mid + 1;
    }
    return -1;
}

int main()
{
    int n = 9, m = 1953125;
    int ans = NthRootBS(n, m);
    cout << "The answer is: " << ans << "\n";
    return 0;
    return 0;
}