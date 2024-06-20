#include<bits/stdc++.h>

using namespace std;
// better approch (O(n*n))
int maxSubarraySum1(int *arr, int n){

    int maxsum = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        int sum =0;
        for (int j = i; j < n; j++)
        {
            sum+= arr[j];

            maxsum = max(sum,maxsum);
        }
        
    }

    return maxsum;  
    
}
int maxSubarraySum2(int *arr,int n){

    int maxsum = INT_MIN;
    int sum=0;
    for (int i = 0; i < n; i++)
    {
        sum+=arr[i];

        if(maxsum<sum){
            maxsum=sum;
        }

        if(sum<0){
            sum=0;
        }
    }

    return maxsum;
    
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