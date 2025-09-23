/*
| Step                       | Explanation                                                   |
| -------------------------- | ------------------------------------------------------------- |
| Compare person `a` and `b` | If `a` knows `b`, eliminate `a`; else eliminate `b`           |
| Repeat until one remains   | Only one candidate left after elimination                     |
| Verify candidate           | Check if candidate knows no one, and everyone knows candidate |

You need to find if there's a celebrity:
- A celebrity knows no one.
- Everyone knows the celebrity.
If such a person exists, return their index; otherwise, return -1.
*/

#include <iostream>
#include <vector>
using namespace std;


// ✅ Brute-force approach
int celebrityBruteForce(vector<vector<int>> &mat, int n)
{
    for (int i = 0; i < n; i++)
    {
        bool isCelebrity = true;

        for (int j = 0; j < n; j++)
        {
            if (i == j)
                continue;

            if (mat[i][j] == 1 || mat[j][i] == 0)
            {
                isCelebrity = false;
                break;
            }
        }

        if (isCelebrity)
            return i;
    }
    return -1;
}

// ✅ Optimal approach (elimination using two pointers)
int celebrityOptimal(vector<vector<int>> &mat, int n)
{
    int a = 0, b = n - 1;

    // Step 1: Find candidate
    while (a < b)
    {
        if (mat[a][b] == 1)
            a++; // a knows b => a can't be celebrity
        else
            b--; // a doesn't know b => b can't be celebrity
    }

    int candidate = a;

    // Step 2: Verify candidate
    for (int i = 0; i < n; i++)
    {
        if (i != candidate)
        {
            if (mat[candidate][i] == 1 || mat[i][candidate] == 0)
                return -1;
        }
    }

    return candidate;
}

int main()
{
    int n = 3; // Number of people

    // Static matrix initialization (example matrix)
    vector<vector<int>> mat = {
        {1, 1, 0},
        {0, 1, 0},
        {0, 1, 1}};

    // Call both versions
    int celeb1 = celebrityBruteForce(mat, n);
    int celeb2 = celebrityOptimal(mat, n);

    cout << "\nBrute-Force Result: ";
    if (celeb1 == -1)
        cout << "No celebrity\n";
    else
        cout << "Celebrity is person " << celeb1 << endl;

    cout << "Optimal Result: ";
    if (celeb2 == -1)
        cout << "No celebrity\n";
    else
        cout << "Celebrity is person " << celeb2 << endl;

    return 0;
}
