#include <bits/stdc++.h>

using namespace std;
void helper(int ind, string s, string curr, vector<string> &ans)
{
    if (ind == s.length())
    {
        ans.push_back(curr);
        return;
    }
    // exclude
    helper(ind + 1, s, curr, ans);
    // include
    helper(ind + 1, s, curr + s[ind], ans);
}
vector<string> power_set(string s)
{
    vector<string> ans;
    string curr;
    helper(0, s, curr, ans);
    sort(ans.begin(), ans.end());
    return ans;
}
int main()
{
    string s = "abc";
    vector<string> subsets = power_set(s);
    for (auto &subset : subsets)
    {
        cout << subset << " ";
    }
    cout << endl;
    return 0;
}