/*
Intuition we are taking Max distace which we can store the
- then we chceking for each distact from 1 - maxpossible if all count place return true else return false
*/

#include <bits/stdc++.h>
using namespace std;

bool canWePlace(vector<int> &stalls, int dist, int cows)
{
    int n = stalls.size();
    int cntCows = 1;
    int last = stalls[0];
    for (int i = 1; i < n; i++)
    {
        if (stalls[i] - last >= dist)
        {
            cntCows++;
            last = stalls[i];
        }
        if (cntCows >= cows)
            return true;
    }
    return false;
}
// int aggressiveCows(vector<int> &stalls, int k)
// {
//     int n = stalls.size();
//     sort(stalls.begin(), stalls.end());

//     int limit = stalls[n - 1] - stalls[0];
//     for (int i = 1; i <= limit; i++)
//     {
//         if (canWePlace(stalls, i, k) == false)
//         {
//             return (i - 1);
//         }
//     }
//     return limit;
// }

int aggressiveCows(vector<int> &stalls, int k)
{
    int n = stalls.size();
    sort(stalls.begin(), stalls.end());

    int left = 1, right = stalls[n - 1] - stalls[0];
    int best = 0;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (canWePlace(stalls, mid, k))
        {
            best = mid; // found a possible solution, try for a larger distance
            left = mid + 1;
        }
        else
        {
            right = mid - 1; 
        }
    }
    return best;
}

int main()
{
    vector<int> stalls = {0, 3, 4, 7, 10, 9};
    int k = 4;
    int ans = aggressiveCows(stalls, k);
    cout << "The maximum possible minimum distance is: " << ans << "\n";
    return 0;
}