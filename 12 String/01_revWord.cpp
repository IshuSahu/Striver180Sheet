#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

// Helper to split by '.'
string reverseWords(string str)
{
    string temp = "";
    string ans = "";

    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] != ' ')
        {
            temp += str[i];
        }
        else
        {
            if (temp != "")
            {
                if (ans != "")
                {
                    ans = temp + " " + ans;
                }
                else
                {
                    {
                        ans = temp;
                    }
                }
                temp = "";
            }
        }
    }
    if (temp != "")
    {
        if (ans != "")
        {
            ans = temp + " " + ans;
        }
        else
        {
            {
                ans = temp;
            }
        }
    }
    return ans;
}
int main()
{
    string s= "Ishu Janakram sahu";
    string res = reverseWords(s);
    cout<<s<<endl;
    return 0;
}
