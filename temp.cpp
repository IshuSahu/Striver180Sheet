#include <iostream>

using namespace std;
void print_arr(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
void Merge(int *arr, int start, int mid, int end)
{
    int len1 = mid - start + 1;
    int len2 = end - mid;

    int *first = new int[len1];
    int *second = new int[len2];
    int k = start;
    for (int i = 0; i < len1; i++)
    {
        first[i] = arr[k++];
    }

    k = mid + 1;
    for (int i = 0; i < len2; i++)
    {
        second[i] = arr[k++];
    }

    // Meargin two soted array
    int i, j;
    k = start;
    i = 0;
    j = 0;
    while (i < len1 && j < len2)
    {
        if (first[i] < second[j])
        {
            arr[k] = first[i];
            i++;
        }
        else
        {
            arr[k] = second[j];
            j++;
        }
        k++;
    }
    while (i < len1)
    {
        arr[k] = first[i];
        k++;
        i++;
    }
    while (j < len2)
    {
        arr[k] = second[j];
        k++;
        j++;
    }
    delete (first);
    delete (second);
}
void Merge_sort(int *arr, int start, int end)
{
    int mid;

    if (start < end)
    {
        mid = (start + end) / 2;
        Merge_sort(arr, start, mid);
        Merge_sort(arr, mid + 1, end);
        Merge(arr, start, mid, end);
    }
}
int main()
{
    int arr[] = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 8, 5, 7};
    int size = sizeof(arr) / sizeof(arr[0]);
    print_arr(arr, size);
    Merge_sort(arr, 0, size - 1);
    print_arr(arr, size);
    return 0;
}