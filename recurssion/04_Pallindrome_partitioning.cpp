#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<vector<string>> partition(string s)
    {
        vector<vector<string>> res;
        vector<string> path;
        partitionHelper(0, s, path, res);
        return res;
    }
    void partitionHelper(int ind, string s, vector<string> &path, vector<vector<string>> &res)
    {
        if (ind == s.size())
        {
            res.push_back(path);
            return;
        }
        for (int i = ind; i < s.size(); i++)
        {
            if (ispallindrom(s, ind, i))
            {
                path.push_back(s.substr(ind, i - ind + 1));
                partitionHelper(i + 1, s, path, res);
                path.pop_back();
            }
        }
    }
    bool ispallindrom(string s, int st, int en)
    {
        while (st <= en)
        {
            if (s[st++] != s[en--])
                return false;
        }
        return true;
    }
};
int main()
{
    string s = "aabb";
    Solution obj;
    vector<vector<string>> ans = obj.partition(s);
    int n = ans.size();
    cout << "The Palindromic partitions are :-" << endl;
    cout << " [ ";
    for (auto i : ans)
    {
        cout << "[ ";
        for (auto j : i)
        {
            cout << j << " ";
        }
        cout << "] ";
    }
    cout << "]";

    return 0;
}