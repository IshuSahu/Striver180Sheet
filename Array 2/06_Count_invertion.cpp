


#include <bits/stdc++.h>
using namespace std;

int numberOfInversions(vector<int>&arr, int n) {

    // Count the number of pairs:
    int cnt =0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i+1; j < n; j++)
        {
            if(arr[i]>arr[j]){
                cnt++;
            }
        }
        
    }
    
    return cnt;
}

int Merge(vector<int> &arr, int low, int mid, int high){
    vector<int> temp;
    int left = low;
    int right = mid+1; 
    int cnt=0;

    while (left<=mid && right<=high)
    {
        if(arr[left]<= arr[right]){
            temp.push_back(arr[left++]);
        }
        else{
            temp.push_back(arr[right++]);
            cnt+=(mid-left+1);
        }
    }

    while (left<=mid)
    {
        temp.push_back(arr[left++]);
    }
    while (right<=high)
    {
        temp.push_back(arr[right++]);
    }


    for (int i = low; i < high; i++)
    {
        arr[i] = temp[i-low];
    }
    
    return cnt;
    
    
}
int MergeSort(vector<int> &arr, int low, int high){
    int cnt =0;
    if(low>=high) return cnt;
    int mid =(low+high)/2;

    cnt +=MergeSort(arr,low,mid);
    cnt +=MergeSort(arr,mid+1,high);
    cnt +=Merge(arr,low,mid,high);


    return cnt;
}

int numberOfInversions1(vector<int> &arr, int n){
    return MergeSort(arr, 0, n-1);
}
int main()
{
    vector<int> a = {5, 4, 3, 2, 1};
    int n = 5;
    int cnt = numberOfInversions(a, n);
    // int cnt = numberOfInversions1(a, n);
    cout << "The number of inversions is: "
         << cnt << endl;
    return 0;
}

