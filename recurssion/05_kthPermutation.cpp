/*
Input: N = 3, K = 5

Result: “312”

Explanation: The sequence has 3! permutations as illustrated in the figure above. K = 5 corresponds to the fifth sequence.
*/

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    void permutationHelper(string &s, int index, vector<string> &res)
    {
        if (index == s.size())
        {
            res.push_back(s);
            return;
        }
        for (int i = index; i < s.size(); i++)
        {
            swap(s[i], s[index]);
            permutationHelper(s, index + 1, res);
            // backtrack
            swap(s[i], s[index]);
        }
    }

    string getPermutation(int n, int k)
    {
        string s;
        vector<string> res;
        // create string
        for (int i = 1; i <= n; i++)
        {
            s.push_back(i + '0');
        }
        permutationHelper(s, 0, res);

        sort(res.begin(), res.end());
        for (auto &permute : res)
        {
            for (char i : permute)
            {
                cout << i << " ";
            }
            cout << endl;
        }
        // make k 0-based indexed to point to kth sequence
        auto it = res.begin() + (k - 1);
        return *it;
    }

    string getPermutation1(int n, int k)
    {
        int fact = 1;
        vector<int> numbers;
        for (int i = 1; i < n; i++)
        {
            fact = fact * i;
            numbers.push_back(i);
        }
        numbers.push_back(n);

        string ans = "";
        k = k - 1;
        while (true)
        {
            ans = ans + to_string(numbers[k / fact]);
            numbers.erase(numbers.begin() + k / fact);
            if (numbers.size() == 0)
            {
                break;
            }
            k = k % fact;
            fact = fact / numbers.size();
        }
        return ans;
    }
};

int main()
{
    int n = 4, k = 17;
    Solution obj;
    string ans = obj.getPermutation1(n, k);
    cout << "The Kth permutation sequence is " << ans << endl;

    return 0;
}