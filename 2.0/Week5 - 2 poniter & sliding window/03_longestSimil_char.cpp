#include <bits/stdc++.h>

using namespace std;

int characterReplacementBruteForce(string s, int k)
{
    int maxLen = 0;
    int n = s.size();

    for (int i = 0; i < n; ++i)
    {
        int freq[26] = {0};
        int maxFreq = 0;

        for (int j = i; j < n; ++j)
        {
            freq[s[j] - 'A']++;
            maxFreq = max(maxFreq, freq[s[j] - 'A']);

            int windowLen = j - i + 1;
            int changesNeeded = windowLen - maxFreq;

            if (changesNeeded <= k)
                maxLen = max(maxLen, windowLen);
        }
    }

    return maxLen;
}

/*
High-Level Idea:
Use a sliding window to find the longest valid window where:

Number of characters to change = Window length - frequency of most common character in the window
If this number ≤ k, the window is valid.
*/
int characterReplacementOptimal(string s, int k)
{
    vector<int> freq(26, 0);
    int maxFreq = 0, maxLen = 0;
    int left = 0;

    for (int right = 0; right < s.size(); ++right)
    {
        freq[s[right] - 'A']++;
        maxFreq = max(maxFreq, freq[s[right] - 'A']);

        while ((right - left + 1) - maxFreq > k)
        {
            freq[s[left] - 'A']--;
            left++;
        }

        maxLen = max(maxLen, right - left + 1);
    }

    return maxLen;
}

int main()
{
    string s1 = "ABAB";
    int k1 = 2;
    cout << "Brute Force Output: " << characterReplacementBruteForce(s1, k1) << endl;
    cout << "Optimal Output: " << characterReplacementOptimal(s1, k1) << endl;

    string s2 = "AABABBBA";
    int k2 = 1;
    cout << "Brute Force Output: " << characterReplacementBruteForce(s2, k2) << endl;
    cout << "Optimal Output: " << characterReplacementOptimal(s2, k2) << endl;

    return 0;
}
