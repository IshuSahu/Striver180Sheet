#include <bits/stdc++.h>

using namespace std;
void rotate(vector<int> &nums, int k)
{
    int n = nums.size();
    k = k % n;
    vector<int> rotated(n);

    for (int i = 0; i < n; ++i)
    {
        rotated[(i + k) % n] = nums[i];
    }

    nums = rotated;
}
int main()
{

    return 0;
}