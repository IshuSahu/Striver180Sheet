
#include <bits/stdc++.h>
using namespace std;

int countPairs(vector<int> &a, int n)
{ // O(n*N)
    // Count the number of pairs:
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (a[i] > 2 * a[j])
                cnt++;
        }
    }
    return cnt;
}

// We will e using merge sort

void Merge(vector<int> &arr, int low, int mid, int high)
{
    vector<int> temp;    // temporary array
    int left = low;      // starting index of left half of arr
    int right = mid + 1; // starting index of right half of arr

    // storing elements in the temporary array in a sorted manner//

    while (left <= mid && right <= high)
    {
        if (arr[left] <= arr[right])
        {
            temp.push_back(arr[left]);
            left++;
        }
        else
        {
            temp.push_back(arr[right]);
            right++;
        }
    }

    // if elements on the left half are still left //

    while (left <= mid)
    {
        temp.push_back(arr[left]);
        left++;
    }

    //  if elements on the right half are still left //
    while (right <= high)
    {
        temp.push_back(arr[right]);
        right++;
    }

    // transfering all elements from temporary to arr //
    for (int i = low; i <= high; i++)
    {
        arr[i] = temp[i - low];
    }
}
int countPair(vector<int> &arr, int low, int mid, int high)
{
    int cnt = 0, right = mid + 1;
    for (int i = low; i <=mid; i++)
    {
    // while (right <= high && (long long)arr[i] > 2LL * arr[right])

        while (right <= high && arr[i] > 2 * arr[right])
        {
            right++;
        }
        cnt = cnt + (right - (mid + 1));
    }
    return cnt;
}
int mergeSort(vector<int> &arr, int low, int high)
{
    int cnt = 0;
    if (low >= high)
        return cnt;
    int mid = (low + high) / 2;
    cnt += mergeSort(arr, low, mid);
    cnt += mergeSort(arr, mid + 1, high);
    cnt += countPair(arr, low, mid, high); // modification
    Merge(arr, low, mid, high);

    return cnt;
}
int team(vector<int> &skill, int n)
{
    return mergeSort(skill, 0, n - 1);
}

int main()
{
    vector<int> a = {1, 3, 2, 3, 1};
    int n = a.size();
    // int cnt = countPairs(a, n);
    int cnt = team(a, n);
    cout << "The number of reverse pair is: "
         << cnt << endl;
    return 0;
}
