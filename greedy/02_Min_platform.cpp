/*
Input: N=6,
arr[] = {9:00, 9:45, 9:55, 11:00, 15:00, 18:00}
dep[] = {9:20, 12:00, 11:30, 11:50, 19:00, 20:00}

Output:3
*/

#include <bits/stdc++.h>
using namespace std;

int countPlatforms(int n, int arr[], int dep[])
{
    int ans = 1; 
    for (int i = 0; i <= n - 1; i++)
    {
        int count = 1; 
        for (int j = i + 1; j <= n - 1; j++)
        {
            //Imp
            if ((arr[i] >= arr[j] && arr[i] <= dep[j]) ||
                (arr[j] >= arr[i] && arr[j] <= dep[i]))
            {
                count++;
            }
        }
        ans = max(ans, count); 
    }
    return ans;
}
int countPlatforms1(int n,int arr[],int dep[])
 {
    sort(arr,arr+n);
    sort(dep,dep+n);
 
    int ans=1;
    int count=1;
    int i=1,j=0;
    while(i<n && j<n)
    {
        if(arr[i]<=dep[j]) //one more platform needed
        {
            count++;
            i++;
        }
        else //one platform can be reduced
        {
            count--;
            j++;
        }
        ans=max(ans,count); //updating the value with the current maximum
    }
    return ans;
 }
int main()
{
    int arr[] = {900, 945, 955, 1100, 1500, 1800};
    int dep[] = {920, 1200, 1130, 1150, 1900, 2000};
    int n = sizeof(dep) / sizeof(dep[0]);
    // cout << "Minimum number of Platforms required " << countPlatforms(n, arr, dep) << endl;
    cout << "Minimum number of Platforms required " << countPlatforms1(n, arr, dep) << endl;
}