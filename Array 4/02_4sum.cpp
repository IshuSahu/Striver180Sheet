#include <bits/stdc++.h>

using namespace std;
// vector<vector<int>> fourSum(vector<int> arr, int Target)
// {
//     int n = arr.size();
//     set<vector<int>> st;
//     for (int i = 0; i < n; i++)
//     {
//         for (int j = i+1; j < n; j++)
//         {
//             set<long long> hset;
//             for (int k = j+1; k < n; k++)
//             {
//                 long long sum = arr[i] + arr[j];
//                 sum += arr[k];
//                 long long forth = Target - sum;
//                 if(hset.find(forth) != hset.end()){
//                     vector<int> temp = {arr[i],arr[j],arr[k], (int)forth};
//                     sort(temp.begin(),temp.end());
//                     st.insert(temp);
//                 }
//                 hset.insert(arr[k]);
//             }
//         }

//     }
//     vector<vector<int>> ans(st.begin(), st.end());
//     return ans;
// }

//Time Complexity: O(N3), where N = size of the array.
// Space Complexity: O(no. of quadruplets),
vector<vector<int>> fourSum(vector<int> nums, int target) 
{
    int n = nums.size(); // size of the array
    vector<vector<int>> ans;

    // sort the given array:
    sort(nums.begin(), nums.end());

    // calculating the quadruplets:
    for (int i = 0; i < n; i++)
    {
        // avoid the duplicates while moving i:
        if (i > 0 && nums[i] == nums[i - 1])
            continue;
        for (int j = i + 1; j < n; j++)
        {
            // avoid the duplicates while moving j:
            if (j > i + 1 && nums[j] == nums[j - 1])
                continue;

            // 2 pointers:
            int k = j + 1;
            int l = n - 1;
            while (k < l)
            {
                long long sum = nums[i];
                sum += nums[j];
                sum += nums[k];
                sum += nums[l];
                if (sum == target)
                {
                    vector<int> temp = {nums[i], nums[j], nums[k], nums[l]};
                    ans.push_back(temp);
                    k++;
                    l--;

                    // skip the duplicates:
                    while (k < l && nums[k] == nums[k - 1])
                        k++;
                    while (k < l && nums[l] == nums[l + 1])
                        l--;
                }
                else if (sum < target)
                    k++;
                else
                    l--;
            }
        }
    }

    return ans;
}

int main()
{
    vector<int> nums = {4, 3, 3, 4, 4, 2, 1, 2, 1, 1};
    int target = 9;
    vector<vector<int>> ans = fourSum(nums, target);
    cout << "The quadruplets are: \n";
    for (auto it : ans)
    {
        cout << "[";
        for (auto ele : it)
        {
            cout << ele << " ";
        }
        cout << "] ";
    }
    cout << "\n";
    return 0;
    return 0;
}