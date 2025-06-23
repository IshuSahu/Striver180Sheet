#include <bits/stdc++.h>
using namespace std;

void reverseString(string str)
{
    stack<string> st;
    string word = "";

    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == ' ')
        {
            st.push(word);
            word = "";
        }
        else
        {
            word += str[i];
        }
    }

    // Push the last word
    if (!word.empty())
        st.push(word);

    // Print words in reverse order
    while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }
}

int main()
{
    string str = "My Name is Ishu";
    reverseString(str);
    return 0;
}
