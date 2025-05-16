
/*
value > n/2
*/

#include <bits/stdc++.h>
using namespace std;

int majorityElement(vector<int> v)
{

    int n = v.size();

    map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        mp[v[i]]++;
    }

    for (auto &&i : mp)
    {
        if (i.second > n / 2)
        {
            return i.first;
        }
    }
    return -1;
}
// Moore Voting Algo
int majorityElement1(vector<int> v)
{

    int n = v.size();
    int ele = -1, cnt = 0;
    ;
    for (int i = 0; i < n; i++)
    {
        if (cnt == 0)
        {
            ele = v[i];
            cnt++;
        }
        if (v[i] == ele)
            cnt++;
        else
            cnt--;
    }
    cnt =0;
    for (int i = 0; i < n; i++)
    {
        if(v[i]==ele){
            cnt++;
        }
        if(cnt>(n/2)){
            return ele;
        }
    }
    

    return -1;
}

int main()
{
    vector<int> arr = {2, 2, 1, 1, 1, 2, 2};
    // int ans = majorityElement(arr);
    int ans = majorityElement1(arr);
    cout << "The majority element is: " << ans << endl;
    return 0;
}
