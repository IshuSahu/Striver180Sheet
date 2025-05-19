#include<bits/stdc++.h>

using namespace std;


int solve(string str)
{
    if (str.length() == 0)
        return 0;
    int maxL = 0;

    unordered_set<int> st;
    int l=0;
    for (int i = 0; i < str.length(); i++)
    {
        if(st.find(str[i])!=st.end()){
            while (l<i && st.find(str[i])!=st.end())
            {
                st.erase(str[l]);
                l++;
            }
            
        }
        maxL= max(maxL,i-l+1);
        cout<<l<<endl;
        st.insert(str[i]);
    }
    return maxL;
}

int main()
{
    string str = "abcaabcdba";
    cout << "The length of the longest substring without repeating characters is " << solve(str);
    return 0;
}