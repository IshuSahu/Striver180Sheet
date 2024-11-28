#include <bits/stdc++.h>
using namespace std;

bool linearSearch(vector<int> &a, int num)
{
    int n = a.size(); // size of array
    for (int i = 0; i < n; i++)
    {
        if (a[i] == num)
            return true;
    }
    return false;
}
bool binarySerch(vector<int> &a, int num)
{

    int n = a.size();
    int low = 0;
    int high = n - 1;
    while (low <=high)
    {
        int mid = (low + high) / 2;
        // cout<<a[mid]<<" \n";
        if (a[mid] == num)
            return true;
        else if (a[mid] > num)
            high = mid - 1;
        else
            low = mid + 1;
    }
    return false;
}
// Time Complexity: O(N2), N = size of the given array.
int longestSuccessiveElements(vector<int> &a)
{
    int n = a.size(); // size of array
    int longest = 1;
    // pick a element and search for its
    // consecutive numbers:
    for (int i = 0; i < n; i++)
    {
        int x = a[i];
        int cnt = 1;
        // search for consecutive numbers
        // using linear search:
        while (linearSearch(a, x + 1) == true)
        {
            x += 1;
            cnt += 1;
        }

        longest = max(longest, cnt);
    }
    return longest;
}


/// Time Complexity: O(N*logN), N = size of the given array.
int longestSuccessiveElements1(vector<int> &a)
{
    sort(a.begin(), a.end()); //n*long n
    int n = a.size();
    // for (int i = 0; i < n; i++)
    // {
    //     cout<<a[i]<<" ";
    // }
    
    int longestCount = 0;
    for (int i = 0; i < n; i++)
    {
        int cnt = 1;
        int x = a[i];
        while (binarySerch(a, x + 1) == true)
        {
            x = x + 1;
            cnt++;
        }
        if (longestCount < cnt)
            longestCount = cnt;
    }
    return longestCount;
}

int longestSuccessiveElements2(vector<int> &a)
{
    int n = a.size();
    int longestCount =0;
    unordered_set<int> st;
    for (int i = 0; i < n; i++)
    {
        st.insert(a[i]);
    }


    for(auto it: st){
        if(st.find(it-1) == st.end()){
            int cnt =1;
            int x = it;
            while (st.find(x+1)!=st.end())
            {
                x++;
                cnt++;
            }
            longestCount = max(longestCount,cnt);
            
        }
    }
    return longestCount;
    
}
int main()
{
    vector<int> a = {100, 200, 1, 2, 3, 4, 5};
    // int ans = longestSuccessiveElements(a);
    // int ans = longestSuccessiveElements1(a);
    int ans = longestSuccessiveElements2(a);
    cout << "The longest consecutive sequence is " << ans << "\n";
    return 0;
}
