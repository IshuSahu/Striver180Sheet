#include <bits/stdc++.h>
using namespace std;

string removeDuplicateLetters(string s)
{
    vector<int> count(26, 0);
    vector<bool> visited(26, false);

    // Count frequency of each character
    for (char c : s)
    {
        count[c - 'a']++;
    }

    stack<char> st;

    for (char c : s)
    {
        count[c - 'a']--;

        if (visited[c - 'a'])
            continue;

        // Remove larger letters from stack if they appear later again
        while (!st.empty() && c < st.top() && count[st.top() - 'a'] > 0)
        {
            visited[st.top() - 'a'] = false;
            st.pop();
        }
        st.push(c);
        visited[c - 'a'] = true;
        /*
        for char = 'a'
        count[a]-- → 0
        not visited
        'a' < 'c' and count[c] > 0 → pop 'c', mark unvisited
        'a' < 'b' and count[b] > 0 → pop 'b', mark unvisited
        push 'a', visited[a] = true
        stack: ['a']
        */
    }

    // Build result from stack
    string result = "";
    while (!st.empty())
    {
        result = st.top() + result;
        st.pop();
    }

    return result;
}

int main()
{
    string input1 = "bcabc";
    string input2 = "cbacdcbc";

    cout << "Input: " << input1 << " => Output: " << removeDuplicateLetters(input1) << endl;
    cout << "Input: " << input2 << " => Output: " << removeDuplicateLetters(input2) << endl;

    return 0;
}
