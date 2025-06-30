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
vector<int> computeLPS(string s) {
    int n = s.length();
    vector<int> lps(n, 0);
    int len = 0;

    // Loop through the string to fill the LPS array
    for (int i = 1; i < n; ) {
        if (s[i] == s[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if (len != 0) {
                len = lps[len - 1];  // instead of resetting len to 0, try to fall back
            } else {
                lps[i] = 0; //If the fallback leads to len = 0, then result[i] is set to 0.
                i++;
            }
        }
    }
    cout<<s<<endl;
     for (int i = 0; i < lps.size(); i++) {
        cout << lps[i] << "";
    }
    cout<<endl;
    return lps;
}

int minCharsToMakePalindrome(string s) {
    string rev = s;
    reverse(rev.begin(), rev.end());
    string combined = s + "#" + rev;
    vector<int> lps = computeLPS(combined);
    return s.length() - lps.back();
}

int main() {
    string s1 = "aacecaaa";
    string s2 = "abcd";

    cout << minCharsToMakePalindrome(s1) << endl; // Output: 1
    cout << minCharsToMakePalindrome(s2) << endl; // Output: 3

    
    return 0;
}
