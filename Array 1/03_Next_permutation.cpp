#include <bits/stdc++.h>

using namespace std;
void reverse(int *arr, int n)
{
    int st = 0;
    int en = n - 1;
    while (st < en)
    {
        swap(arr[st++], arr[en--]);
    }
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}
void Next_Permutation(int *arr, int n)
{
    int size = n;
    int ind = -1;
    for (int i = size - 2; i >= 0; i--)
    {
        cout << arr[i] << arr[i + 1] << endl;
        if (arr[i] < arr[i + 1])
        {
            ind = i;
            break;
        }
    }
    if (ind == -1)
    {
        reverse(arr, size);
    }
    for (int i = size - 1; i >= ind; i--)
    {
        if (arr[i] > arr[ind])
        {
            swap(arr[i], arr[ind]);
            break;
        }
    }
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
}

int main()
{
    int arr[] = {1, 2, 4, 3};
    Next_Permutation(arr,4);
    // next_permutation(arr, arr + 3);

    // cout << arr[0] << " " << arr[1] << " " << arr[2] << endl;
    return 0;
}