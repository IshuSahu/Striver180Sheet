#include <bits/stdc++.h>

using namespace std;
class Solution
{
public:
    int maxChunksToSorted(vector<int> &arr)
    {
        int n = arr.size();
        vector<int> maxLeft(n), minRight(n);

        maxLeft[0] = arr[0];
        for (int i = 1; i < n; ++i)
        {
            maxLeft[i] = max(maxLeft[i - 1], arr[i]);
        }

        minRight[n - 1] = arr[n - 1];
        for (int i = n - 2; i >= 0; --i)
        {
            minRight[i] = min(minRight[i + 1], arr[i]);
        }

        int chunks = 0;
        for (int i = 0; i < n - 1; ++i)
        {
            if (maxLeft[i] <= minRight[i + 1])
            {
                chunks++;
            }
        }

        // Always count the last chunk (the entire array itself forms a chunk)
        return chunks + 1;
    }
};
int main()
{

    return 0;
}