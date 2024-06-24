#include<bits/stdc++.h>

using namespace std;
vector<int> twoSum(int n, vector<int> &arr, int target) {
    vector<int> ans;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] + arr[j] == target) {
                ans.push_back(i);
                ans.push_back(j);
                return ans;
            }
        }
    }
    return { -1, -1};
}

// better approch using Map;
/*
Time Complexity: O(N), where N = size of the array.
Reason: The loop runs N times in the worst case and searching in a hashmap takes O(1) generally. So the time complexity is O(N).
*/
string twoSum1(int n, int *arr, int target) {

    unordered_map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        int T = target - arr[i];
        if(mp.find(T)!= mp.end()){
            return "Yess";
            // vector<arr> {mp[T], i}
        }
        mp[arr[i]] = i;
    }
    
    return "No";
}

int main(){
    int  arr[] = {2,6,5,8 ,7, 11};
    int n = sizeof(arr)/ sizeof(arr[0]);
    int T=  14;
    // for (int i = 0; i < n; i++) {
    //     for (int j = i + 1; j < n; j++) {
    //         if (arr[i] + arr[j] == T){
    //           cout<< "YES";  
    //             break;
    //         } 
    //     }
    // }
    // cout<< "NO";
    cout<< twoSum1(n, arr, T);
    
    return 0;
}