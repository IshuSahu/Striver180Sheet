#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<string> topKFrequentbrut(vector<string> &words, int k)
    {
        unordered_map<string, int> freq;
        for (const string &word : words)
        {
            freq[word]++;
        }
        vector<pair<string, int>> wordList(freq.begin(), freq.end());
        sort(wordList.begin(), wordList.end(), [](const pair<string, int> &a, const pair<string, int> &b)
             {
            if (a.second != b.second)
                return a.second > b.second; 
            return a.first < b.first; });

        vector<string> result;
        for (int i = 0; i < k && i < wordList.size(); ++i)
        {
            result.push_back(wordList[i].first);
        }

        return result;
    }
};

int main()
{
    vector<string> words = {"i", "love", "leetcode", "i", "love", "coding"};
    int k = 2;

    Solution sol;
    vector<string> result = sol.topKFrequentbrut(words, k);
    // vector<string> result = sol.topKFrequent(words, k);

    cout << "Top " << k << " frequent words:\n";
    for (const string &word : result)
    {
        cout << word << endl;
    }

    return 0;
}
