/*
for(auto it : s):
This line initiates a range-based for loop, which iterates over each element in the container s.
auto is a type specifier that automatically deduces the type of it based on the type of elements in s.
it is the loop variable that will take on the value of each element in s as the loop iterates.
*/
#include <bits/stdc++.h>
using namespace std;
bool isValid(string s)
{
    stack<char> st;

    //for(int i=0 ;i<st.length;i++)
    for (auto it : s)
    {
        if (it == '(' || it == '{' || it == '[')
            st.push(it);
        else
        {
            if (st.size() == 0)
                return false;
            char ch = st.top();
            st.pop(); // u need to be pop that ele
            /*else if it is nonempty then we will check if the topmost element of the stack is the opposite pair of the closing bracket or not.*/
            if ((it == ')' && ch == '(') or (it == ']' && ch == '[') or (it == '}' && ch == '{'))
                continue;
            else
                return false;
        }
    }
    return st.empty();
}
int main()
{
    string s = "()[{}{()}]";
    if (isValid(s))
        cout << "True" << endl;
    else
        cout << "False" << endl;
}