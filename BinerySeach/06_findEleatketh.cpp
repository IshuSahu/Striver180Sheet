
#include <bits/stdc++.h>
using namespace std;

int kthElement(vector<int> &a, vector<int> &b, int m, int n, int k)
{
    vector<int> arr3;

    // apply the merge step:
    int i = 0, j = 0;
    while (i < m && j < n)
    {
        if (a[i] < b[j])
            arr3.push_back(a[i++]);
        else
            arr3.push_back(b[j++]);
    }

    // copy the left-out elements:
    while (i < m)
        arr3.push_back(a[i++]);
    while (j < n)
        arr3.push_back(b[j++]);
    return arr3[k - 1];
}
/*
TC: O(m+n)
SC: O(m+n)
*/

int kthElement2(vector<int> &a, vector<int> &b, int m, int n, int k)
{
    int i = 0, j = 0;
    int cnt = 0; // Use 0-based index for counting
    while (i < m && j < n)
    {
        if (a[i] < b[j])
        {
            cnt++;
            if (cnt == k)
                return a[i];
            i++;
        }
        else
        {
            cnt++;
            if (cnt == k)
                return b[j];
            j++;
        }
    }
    while (i < m)
    {
        cnt++;
        if (cnt == k)
            return a[i];
        i++;
    }
    while (j < n)
    {
        cnt++;
        if (cnt == k)
            return b[j];
        j++;
    }
    return -1; // In case k is out of the bounds
}
/*
TC: O(m+n)
SC:
*/

int findKthElement(vector<int> &a, vector<int> &b, int k)
{
    int n1 = a.size(), n2 = b.size();

    // Always binary search on smaller array
    if (n1 > n2)
        return findKthElement(b, a, k);

    int low = max(0, k - n2), high = min(k, n1); ////IMP

    while (low <= high)
    {
        int cut1 = (low + high) / 2;
        int cut2 = k - cut1;

        int l1 = (cut1 == 0) ? INT_MIN : a[cut1 - 1];
        int l2 = (cut2 == 0) ? INT_MIN : b[cut2 - 1];

        int r1 = (cut1 == n1) ? INT_MAX : a[cut1];
        int r2 = (cut2 == n2) ? INT_MAX : b[cut2];

        if (l1 <= r2 && l2 <= r1)
        {
            return max(l1, l2); /// IMP
        }
        else if (l1 > r2)
        {
            high = cut1 - 1;
        }
        else
        {
            low = cut1 + 1;
        }
    }

    return -1; // k is out of bounds
}
int main()
{
    vector<int> a = {5, 5, 8, 8, 8, 9, 11, 11, 11, 11, 11};
    vector<int> b = {4, 4, 4, 4, 6, 8, 9, 9, 9, 11, 13};

    cout << "The k-ht element of two sorted array is: " << kthElement(a, b, a.size(), b.size(), 2) << '\n';
}
