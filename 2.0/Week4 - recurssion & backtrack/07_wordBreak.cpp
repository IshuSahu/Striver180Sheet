#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

// class Solution {
// public:
//     bool backtrack(string s, unordered_set<string>& dict, int ind) {
//         if (ind == s.size()) {
//             return true;
//         }

//         for (int i = ind + 1; i <= s.size(); ++i) {
//             string word = s.substr(ind, i - ind);
//             // cout<<word<<endl;
//             if (dict.find(word) != dict.end()) {
//                 if (backtrack(s, dict, i)) {
//                     return true;
//                 }
//             }
//         }

//         return false;
//     }

//     bool wordBreak(string s, vector<string>& wordDict) {
//         unordered_set<string> dict(wordDict.begin(), wordDict.end());
//         return backtrack(s, dict, 0);
//     }
// };

// DP Approch
class Solution
{
public:
    bool backtrack(string &s, unordered_set<string> &dict, vector<int> &Dp, int ind)
    {
        if (ind == s.size())
        {
            return true;
        }

        if (Dp[ind] != -1)
        {
            return Dp[ind] == 1;
        }

        for (int i = ind + 1; i <= s.size(); ++i)
        {
            string word = s.substr(ind, i - ind);
            if (dict.find(word) != dict.end())
            {
                if (backtrack(s, dict, Dp, i))
                {
                    Dp[ind] = 1;
                    return true;
                }
            }
        }

        Dp[ind] = 0;
        return false;
    }

    bool wordBreak(string s, vector<string> &wordDict)
    {
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        vector<int> Dp(s.size(), -1); // -1 means uncomputed, 0 means false, 1 means true
        return backtrack(s, dict, Dp, 0);
    }
};

int main()
{
    Solution solution;

    // Test case 1
    string s1 = "leetcode";
    vector<string> wordDict1 = {"leet", "code"};
    cout << solution.wordBreak(s1, wordDict1) << endl; // Output: true

    // Test case 2
    string s2 = "applepenapple";
    vector<string> wordDict2 = {"apple", "pen"};
    cout << solution.wordBreak(s2, wordDict2) << endl; // Output: true

    // Test case 3
    string s3 = "catsandog";
    vector<string> wordDict3 = {"cats", "dog", "sand", "and", "cat"};
    cout << solution.wordBreak(s3, wordDict3) << endl; // Output: false

    return 0;
}
