
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
int kthElement2(vector<int> &a, vector<int> &b, int m, int n, int k)
{
    int i = 0, j = 0;
    int cnt = 0; // Use 0-based index for counting
    while (i < m && j < n) {
        if (a[i] < b[j]) {
            cnt++;
            if (cnt == k) return a[i];
            i++;
        } else {
            cnt++;
            if (cnt == k) return b[j];
            j++;
        }
    }
    while (i < m) {
        cnt++;
        if (cnt == k) return a[i];
        i++;
    }
    while (j < n) {
        cnt++;
        if (cnt == k) return b[j];
        j++;
    }
    return -1; // In case k is out of the bounds
}
int main()
{
  vector<int> a = {5, 5, 8, 8, 8, 9, 11, 11, 11, 11, 11};
    vector<int> b = {4, 4, 4, 4, 6, 8, 9, 9, 9, 11, 13};

    cout << "The k-ht element of two sorted array is: " << kthElement2(a, b, a.size(), b.size(), 2) << '\n';
}
