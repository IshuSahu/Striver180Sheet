#include<bits/stdc++.h>

using namespace std;
int maxSubarraySum2(int *arr, int n){
    int max_sum= INT_MIN;
    int sum=0;
    for (int i = 0; i < n; i++)
    {
        sum=0;
        for (int j = i; j < n; j++)
        {
            sum+=arr[j];
            if(sum>max_sum){
                max_sum = sum;
            }
        }
        
    }
    
    return max_sum;
    
}
int main(){
    int arr[] = { -2, 1, -3, 4, -1, 2, 1, -5, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    // int maxSum = maxSubarraySum1(arr, n);
    int maxSum = maxSubarraySum2(arr, n);
    cout << "The maximum subarray sum is: " << maxSum << endl;
    return 0;
    return 0;
}