#include <iostream>
#include <string>
using namespace std;
// Repeated String Match

int repeatedStringMatch(string a, string b)
{
    string repeated = a;
    int count = 1;

    // Keep appending until length of repeated is at least that of b
    while (repeated.length() < b.length())
    {
        repeated += a;
        count++;
    }

    // Check if b is a substring of current repeated string
    if (repeated.find(b) != string::npos)
    {
        return count;
    }

    // Check one more repetition in case b is across the boundary
    repeated += a;
    count++;
    cout << repeated << endl;
    if (repeated.find(b) != string::npos)
    {
        return count;
    }

    return -1;
}

int main()
{
    string a = "abcd";
    string b = "cdabcdab";

    cout << repeatedStringMatch(a, b) << endl;  // Output: 3

    a = "abcabc";
    b = "cab";

    // if (a.find(b) != -1) // u can use -1; repeated.find(b) return index so WRONG! Only works if index != 0 but in this case substring can be strart from 0 too
    // {
    //     cout << "Found!" << endl;
    // }
    // else
    // {
    //     cout << "Not found!" << endl;
    // }

    return 0;
}
