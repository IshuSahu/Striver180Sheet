#include <bits/stdc++.h>

using namespace std;
void PrintArr(vector<int> arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
void MinHepify(vector<int> &arr, int n, int ind)
{
    int Lowest = ind;

    while (true)
    {
        int left = 2 * ind + 1;
        int right = 2 * ind + 2;

        if (left < n && arr[left] < arr[Lowest])
        {
            Lowest = left;
        }
        if (right < n && arr[right] < arr[Lowest])
        {
            Lowest = right;
        }

        if (Lowest != ind)
        {
            swap(arr[ind], arr[Lowest]);
            ind = Lowest;
        }
        else
        {
            break;
        }
    }
}
void MaxHepify(vector<int> &arr, int n, int ind)
{
    int largest = ind;

    while (true)
    {
        int left = 2 * ind + 1;
        int right = 2 * ind + 2;

        if (left < n && arr[left] > arr[largest])
        {
            largest = left;
        }
        if (right < n && arr[right] > arr[largest])
        {
            largest = right;
        }

        if (largest != ind)
        {
            swap(arr[ind], arr[largest]);
            ind = largest;
        }
        else
        {
            break;
        }
    }
}

int main()
{
    vector<int> arr = {1, 2, 6, 4, 5, 3};
    PrintArr(arr);
    int n = arr.size();
    cout << "Max Heap" << endl;
    for (int i = (n / 2) - 1; i >= 0; i--)
    {
        MaxHepify(arr, n, i);
    }
    PrintArr(arr);
    cout << "min Heap" << endl;
    for (int i = (n / 2) - 1; i >= 0; i--)
    {
        MinHepify(arr, n, i);
    }
    PrintArr(arr);

    return 0;
}