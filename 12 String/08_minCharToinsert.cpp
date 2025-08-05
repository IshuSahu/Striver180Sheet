/*
Find the minimum number of characters that need to be inserted at the beginning of a string to make it a palindrome.
 Example:
"aacecaaa" → Insert 1 character ('a') at the beginning → "aaacecaaa" (palindrome)

"abcd" → Insert 3 characters ("dcb") at the beginning → "dcbabcd"

Efficient Approach: Use KMP-based LPS (Longest Prefix Suffix)
    Construct a new string: original + '#' + reversed
    Build the LPS array of this new string.
    The last value in the LPS array tells us the length of the longest palindromic prefix.
    Then:
        Min insertions = original.length() - LPS value
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Build LPS (Longest Prefix Suffix) array (KMP helper)
vector<int> computeLPS(string s)
{
    int n = s.length();
    vector<int> lps(n, 0);
    int len = 0;

    // Loop through the string to fill the LPS array
    for (int i = 1; i < n;)
    {
        if (s[i] == s[len])
        {
            len++;
            lps[i] = len;
            i++;
        }
        else
        {
            if (len != 0)
            {
                len = lps[len - 1]; // instead of resetting len to 0, try to fall back
            }
            else
            {
                lps[i] = 0; // If the fallback leads to len = 0, then result[i] is set to 0.
                i++;
            }
        }
    }
    cout << s << endl;
    for (int i = 0; i < lps.size(); i++)
    {
        cout << lps[i] << "";
    }
    cout << endl;
    return lps;
}

int minCharsToMakePalindrome(string s)
{
    string rev = s;
    reverse(rev.begin(), rev.end());
    string combined = s + "#" + rev;
    vector<int> lps = computeLPS(combined);
    return s.length() - lps.back();
}

bool isPalindrome(const string &s, int start, int end)
{
    while (start < end)
    {
        if (s[start] != s[end])
            return false;
        start++;
        end--;
    }
    return true;
}

int minCharsToMakePalindrome2(const string &s)
{
    int n = s.length();

    for (int i = n - 1; i >= 0; i--)
    {
        if (isPalindrome(s, 0, i))
        {
            cout << n << " " << i << endl;
            return n - (i + 1);
        }
    }

    return n - 1; // worst case: no prefix is palindrome
}
/*
Find the longest prefix of the string that is already a palindrome.
Then, whatever characters are after that prefix (i.e., the suffix), you must reverse and add them at the beginning to make the whole string a palindrome.
*/
string makePalindrome(string s);
int main()
{
    string s2 = "aacecaaa";
    string s1 = "abcd"; // worst case input

    cout << minCharsToMakePalindrome2(s1) << endl; // Output: 1
    cout << minCharsToMakePalindrome2(s2) << endl; // Output: 3
    cout << makePalindrome(s2) << endl;            // Output: 3
    cout << makePalindrome(s2) << endl;            // Output: 3

    return 0;
}

string makePalindrome(string s)
{
    int n = s.length();
    int i;
    for (i = n - 1; i >= 0; i--)
    {
        if (isPalindrome(s, 0, i))
        {
            break;
        }
    }

    // Characters after the palindrome prefix
    string suffix = s.substr(i + 1);

    // Reverse the suffix and add at the front
    reverse(suffix.begin(), suffix.end());
    return suffix + s;
}