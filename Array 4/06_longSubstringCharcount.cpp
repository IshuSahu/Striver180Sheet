#include <bits/stdc++.h>

using namespace std;
// TC--> O( N2 )
// SC--> O(N) where N is the size of HashSet taken for storing the elements
int solve(string str)
{
    if (str.length() == 0)
        return 0;
    int maxL = 0;

    for (int i = 0; i < str.length(); i++)
    {
        unordered_set<int> st;
        for (int j = i; j < str.length(); j++)
        {
            if (st.find(str[j]) != st.end())
            {
                maxL = max(maxL, j - i);
                break;
            }
            st.insert(str[i]);
        }
    }
    cout << maxL << endl;
    return maxL;
}

/*
TC: O( 2*N ) (sometimes left and right both have to travel a complete array)
SC: O(N) where N is the size of HashSet taken for storing the elements*/
int solve2(string str)
{
    if (str.length() == 0)
        return 0;
    int maxL = 0;
    unordered_set<int> st;
    int l = 0; // Pointer to the left side of the window

    for (int i = 0; i < str.length(); i++)                                                                                      
    { 
        if (st.find(str[i]) != st.end())
        { 
            while (l < i && st.find(str[i]) != st.end())
            { 
                st.erase(str[l]);
                l++;
            }
        }

        st.insert(str[i]);
        maxL = max(maxL, i - l + 1); // Correct calculation of maxL
    }

    return maxL;
}

int lengthofLongestSubstring(string s)
{
    vector<int> mpp(256, -1);

    int left = 0, right = 0;
    int n = s.size();
    int len = 0;
    while (right < n)
    {
        if (mpp[s[right]] != -1)
            left = max(mpp[s[right]] + 1, left);

        mpp[s[right]] = right;

        len = max(len, right - left + 1);
        right++;
    }
    return len;
}

int main()
{
    string str = "abcaabcdba";
    cout << "The length of the longest substring without repeating characters is " << solve2(str);
    return 0;
}