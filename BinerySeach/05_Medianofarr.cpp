#include <bits/stdc++.h>
using namespace std;

double median(vector<int> &a, vector<int> &b)
{
    int n1 = a.size(), n2 = b.size();

    vector<int> arr3;
    int i = 0, j = 0;
    while (i < n1 && j < n2)
    {
        if (a[i] < b[j])
            arr3.push_back(a[i++]);
        else
            arr3.push_back(b[j++]);
    }

    while (i < n1)
        arr3.push_back(a[i++]);
    while (j < n2)
        arr3.push_back(b[j++]);

    int n = n1 + n2;
    if (n % 2 == 1)
    {
        return (double)arr3[n / 2];
    }
    else
    {
        return ((double)arr3[n / 2] + (double)arr3[(n / 2) - 1]) / 2.0;
    }
}
/*
Time Complexity: O(n1+n2)
Space Complexity: O(n1+n2)
*/

double median1_2(vector<int> &a, vector<int> &b)
{
    // size of two given arrays:
    int n1 = a.size(), n2 = b.size();
    int n = n1 + n2; // total size
    // required indices:
    int ind2 = n / 2;
    int ind1 = ind2 - 1;
    int cnt = 0;
    int ind1el = -1, ind2el = -1;

    // apply the merge step:
    int i = 0, j = 0;
    while (i < n1 && j < n2)
    {
        if (a[i] < b[j])
        {
            if (cnt == ind1)
                ind1el = a[i];
            if (cnt == ind2)
                ind2el = a[i];
            cnt++;
            i++;
        }
        else
        {
            if (cnt == ind1)
                ind1el = b[j];
            if (cnt == ind2)
                ind2el = b[j];
            cnt++;
            j++;
        }
    }

    // copy the left-out elements:
    while (i < n1)
    {
        if (cnt == ind1)
            ind1el = a[i];
        if (cnt == ind2)
            ind2el = a[i];
        cnt++;
        i++;
    }
    while (j < n2)
    {
        if (cnt == ind1)
            ind1el = b[j];
        if (cnt == ind2)
            ind2el = b[j];
        cnt++;
        j++;
    }

    // Find the median:
    if (n % 2 == 1)
    {
        return (double)ind2el;
    }

    return (double)((double)(ind1el + ind2el)) / 2.0;
}
/*
Time Complexity: O(n1+n2)
Space Complexity: O(1)
*/

// using Bineray search

double findMedianSortedArrays(vector<int> &A, vector<int> &B)
{
    if (A.size() > B.size())
        return findMedianSortedArrays(B, A);

    int n = A.size(), m = B.size();
    int low = 0, high = n;

    while (low <= high)
    {
        int partitionA = (low + high) / 2;
        int partitionB = (n + m + 1) / 2 - partitionA;

        int maxLeftA = (partitionA == 0) ? INT_MIN : A[partitionA - 1];
        int minRightA = (partitionA == n) ? INT_MAX : A[partitionA];

        int maxLeftB = (partitionB == 0) ? INT_MIN : B[partitionB - 1];
        int minRightB = (partitionB == m) ? INT_MAX : B[partitionB];

        if (maxLeftA <= minRightB && maxLeftB <= minRightA)
        {
            if ((n + m) % 2 == 0)
            {
                return (max(maxLeftA, maxLeftB) + min(minRightA, minRightB)) / 2.0;
            }
            else
            {
                return max(maxLeftA, maxLeftB);
            }
        }
        else if (maxLeftA > minRightB)
        {
            high = partitionA - 1; // move left
        }
        else
        {
            low = partitionA + 1; // move right
        }
    }
    return -1; // should never reach
}
int main()
{
    vector<int> a = {1, 4, 7, 10, 12};
    vector<int> b = {2, 3, 6, 9};
    cout << "The median of two sorted array is " << fixed << setprecision(1)
         << findMedianSortedArrays(a, b) << '\n';
}
