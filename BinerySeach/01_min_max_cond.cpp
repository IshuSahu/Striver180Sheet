#include <bits/stdc++.h>
using namespace std;

// Condition function: is x*x >= target?
bool checkMinCondition(long long x, long long target)
{
    return x * x >= target;
}

// Smallest value satisfying condition
long long minSatisfying(long long low, long long high, long long target)
{
    while (low < high)
    {
        long long mid = low + (high - low) / 2;
        if (checkMinCondition(mid, target))
        {
            high = mid; // mid satisfies, try smaller
        }
        else
        {
            low = mid + 1; // mid doesn't satisfy, go right
        }
    }
    return low; // smallest satisfying
}

// For maximum satisfying condition
bool checkMaxCondition(long long x, long long target)
{
    return x * x <= target;
}

long long maxSatisfying(long long low, long long high, long long target)
{
    while (low < high)
    {
        long long mid = low + (high - low + 1) / 2; // bias up
        if (checkMaxCondition(mid, target))
        {
            low = mid; // mid satisfies, try bigger
        }
        else
        {
            high = mid - 1; // mid fails, go smaller
        }
    }
    return low; // largest satisfying
}

int main()
{
    long long target = 30;

    cout << "Smallest x such that x*x >= " << target << " is: "
         << minSatisfying(0, target, target) << "\n";

    cout << "Largest x such that x*x <= " << target << " is: "
         << maxSatisfying(0, target, target) << "\n";

    return 0;
}
