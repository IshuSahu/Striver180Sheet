#include <bits/stdc++.h>

using namespace std;
int MaxProfit(int *arr, int n)
{

    cout << n;
    int maxProfit = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {

            if (arr[i] < arr[j])
            {
                maxProfit = max(maxProfit, arr[j] - arr[i]);
            }
        }
    }
    return maxProfit;
}
int MaxProfit2(int *arr, int n)
{
    int maxProfit = 0;
    int mini = arr[0];
    for (int i = 0; i < n; i++)
    {
        int currProfit = arr[i] - mini;
        maxProfit = max(maxProfit, currProfit);
        mini = min(mini, arr[i]);
    }
    return maxProfit;
}
int main()
{
    int arr[] = {7, 1,5, 3, 6, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    // int maxPro = MaxProfit(arr, n);
    int maxPro = MaxProfit2(arr, n);
    cout << "Max profit: " << maxPro;
    return 0;
}