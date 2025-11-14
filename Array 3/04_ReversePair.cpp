
#include <bits/stdc++.h>
using namespace std;
// O(n*N)
int countPairs(vector<int> &a, int n)
{
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

// We will e using merge sort this will be done in (n*logn);
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
void merge(vector<int> &arr, int l, int m, int r)
{
    vector<int> left(arr.begin() + l, arr.begin() + m + 1);
    vector<int> right(arr.begin() + m + 1, arr.begin() + r + 1);
    int i = 0, j = 0, k = l;

    while (i < left.size() && j < right.size())
    {
        if (left[i] <= right[j])
            arr[k++] = left[i++];
        else
            arr[k++] = right[j++];
    }

    while (i < left.size())
        arr[k++] = left[i++];
    while (j < right.size())
        arr[k++] = right[j++];
}

int countPair(vector<int> &arr, int low, int mid, int high)
{
    int cnt = 0, right = mid + 1;
    for (int i = low; i <= mid; i++)
    {
        // while (right <= high && (long long)arr[i] > 2LL * arr[right])

        while (right <= high && arr[i] > 2 * arr[right])
        {
            right++;
        }
        cnt = cnt + (right - (mid + 1));
        cout<<cnt<<" ";
    }
    cout<<endl;
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

int countPairs2(vector<int> &arr, int n)
{
    return mergeSort(arr, 0, n - 1);
}

int main()
{
    vector<int> a = {40,25,19,12,9,6,2};
    int n = a.size();
    // int cnt = countPairs(a, n);
    int cnt = countPairs2(a, n);
    cout << "The number of reverse pair is: "
         << cnt << endl;
    return 0;
}
