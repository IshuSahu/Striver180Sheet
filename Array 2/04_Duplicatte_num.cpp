#include <bits/stdc++.h>

using namespace std;
// work only if there is single duplicate value
int findDuplicate(vector<int> &arr)
{
    int ans = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        ans = ans ^ arr[i];
    }

    for (int i = 1; i < arr.size(); i++)
    {
        ans = ans ^ i;
    }

    return ans;
}
// m2  sort and find the duplicates
int findDuplicate1(vector<int> &arr)
{
    int n = arr.size();
    sort(arr.begin(), arr.end());
    for (int i = 0; i < n - 1; i++)
    {
        if (arr[i] == arr[i + 1])
        {
            return arr[i];
        }
    }
}

// method 3 Count freq 
int findDuplicate2(vector<int> &arr)
{
    int n = arr.size();
    int freq[n+1] ={0};

    for (int i = 0; i < n; i++)
    {
        if(freq[arr[i]]==0){
            freq[arr[i]] +=1;
        }
        else{
            return arr[i];
            
        }
    }
    
}
int main()
{
    vector<int> arr;
    // arr = {1, 3, 4, 2, 5, 4};
    arr = {1, 1,1,1,1};
    cout << "The duplicate element is " << findDuplicate(arr) << endl;
    cout << "The duplicate element is " << findDuplicate1(arr) << endl;
    cout << "The duplicate element is " << findDuplicate2(arr) << endl;
}

