/*
Input Format: arr = [4,5,6,7,0,1,2,3], k = 0
Result: 4
Explanation: Here, the target is 0. We can see that 0 is present in the given rotated sorted array, nums. Thus, we get output as 4, which is the index at which 0 is present in the array.

Example 2:
Input Format: arr = [4,5,6,7,0,1,2], k = 3
Result: -1
*/
#include <bits/stdc++.h>
using namespace std;

int search(vector<int> &arr, int n, int k)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == k)
            return i;
    }
    return -1;
}
int b_search(vector<int> & arr, int n , int k){
    int low=0;
    int high = n-1;

    while (low<=high)
    {
        int mid = (low+high)/2;
        if(arr[mid]==k) return mid;

        if(arr[low]<=arr[mid]){
            if(arr[low]<=k && k <=arr[mid]){
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        else{
            if(arr[mid]<=k && k<=arr[high]){
                low = mid+1;
            }else{
                high= mid-1;
            }
        }
    }
    return -1;
    
}
int main()
{
    vector<int> arr = {7, 8, 9, 1,0, 2, 3, 4, 5, 6};
    int n = 10, k = 0;
    int ans = search(arr, n, k);
    if (ans == -1)
        cout << "Target is not present.\n";
    else
        cout << "The index is: " << ans << "\n";
    return 0;
}
