// #include <bits/stdc++.h>

// using namespace std;

// class Solution
// {
//     void findPathHelper(int i, int j, vector<vector<int>> &a, int n, vector<string> &ans, string move,
//                         vector<vector<int>> &vis)
//     {
//         if (i == n - 1 && j == n - 1)
//         {
//             ans.push_back(move);
//             return;
//         }

//         // downward
//         if (i + 1 < n && !vis[i + 1][j] && a[i + 1][j] == 1)
//         {
//             vis[i][j] = 1;
//             findPathHelper(i + 1, j, a, n, ans, move + 'D', vis);
//             vis[i][j] = 0;
//         }

//         // left
//         if (j - 1 >= 0 && !vis[i][j - 1] && a[i][j - 1] == 1)
//         {
//             vis[i][j] = 1;
//             findPathHelper(i, j - 1, a, n, ans, move + 'L', vis);
//             vis[i][j] = 0;
//         }

//         // right
//         if (j + 1 < n && !vis[i][j + 1] && a[i][j + 1] == 1)
//         {
//             vis[i][j] = 1;
//             findPathHelper(i, j + 1, a, n, ans, move + 'R', vis);
//             vis[i][j] = 0;
//         }

//         // upward
//         if (i - 1 >= 0 && !vis[i - 1][j] && a[i - 1][j] == 1)
//         {
//             vis[i][j] = 1;
//             findPathHelper(i - 1, j, a, n, ans, move + 'U', vis);
//             vis[i][j] = 0;
//         }
//     }

// public:
//     vector<string> findPath(vector<vector<int>> &m, int n)
//     {
//         vector<string> ans;
//         vector<vector<int>> vis(n, vector<int>(n, 0));

//         if (m[0][0] == 1)
//             findPathHelper(0, 0, m, n, ans, "", vis);
//         return ans;
//     }
// };

// int main()
// {
//     int n = 4;

//     vector<vector<int>> m = {{1, 0, 0, 0}, {1, 1, 0, 1}, {1, 1, 0, 0}, {0, 1, 1, 1}};

//     Solution obj;
//     vector<string> result = obj.findPath(m, n);
//     if (result.size() == 0)
//         cout << -1;
//     else
//         for (int i = 0; i < result.size(); i++)
//             cout << result[i] << " ";
//     cout << endl;

//     return 0;
// }

// if it is graph and need to return bool output
// #include <bits/stdc++.h>

// using namespace std;
// bool isSafe(int **arr, int x, int y, int n)
// {
//     if (x < n && y < n && arr[x][y] == 1)
//     {
//         return true;
//     }
//     return false;
// }
// bool ratInMaze(int **arr, int x, int y, int n, int **solAns)
// {
//     if (x == n - 1 && y == n - 1)
//     {
//         return true;
//     }
//     if (isSafe(arr, x, y, n))
//     {
//         solAns[x][y] = 1;
//         if (ratInMaze(arr, x + 1, y, n, solAns))
//             return true;
//         if (ratInMaze(arr, x, y + 1, n, solAns))
//             return true;
//         solAns[x][y] = 0; // backtrack
//         return false;
//     }
//     return false;
// }
// int main()
// {
//     int n = 4;
//     int defaultMaze[4][4] = {
//         {1, 0, 0, 0},
//         {1, 1, 0, 1},
//         {1, 1, 0, 0},
//         {0, 1, 1, 1}};

//     int **arr = new int *[n];
//     for (int i = 0; i < n; i++)
//     {
//         arr[i] = new int[n];
//         for (int j = 0; j < n; j++)
//         {
//             arr[i][j] = defaultMaze[i][j];
//         }
//     }

//     int **solAns = new int *[n];
//     for (int i = 0; i < n; i++)
//     {
//         solAns[i] = new int[n];
//         for (int j = 0; j < n; j++)
//         {
//             solAns[i][j] = 0;
//         }
//     }

//     if (ratInMaze(arr, 0, 0, n, solAns))
//     {
//         cout << "Solution exists" << endl;
//     }
//     else
//     {
//         cout << "No solution exists";
//     }

//     for (int i = 0; i < n; i++)
//     {
//         delete[] arr[i];
//         delete[] solAns[i];
//     }
//     delete[] arr;
//     delete[] solAns;

//     return 0;
//     return 0;
// }

#include <bits/stdc++.h>

using namespace std;

bool isSafe(int **arr, int x, int y, int n)
{
    if (x >= 0 && y >= 0 && x < n && y < n && arr[x][y] == 1)
    {
        return true;
    }
    return false;
}

void solve(int **arr, int x, int y, int n, int **solAns, string path, vector<string> &paths)
{
    if (x == n - 1 && y == n - 1)
    {
        paths.push_back(path);
        return;
    }
    if (isSafe(arr, x, y, n))
    {
        solAns[x][y] = 1;

        // Move Down
        if (isSafe(arr, x + 1, y, n))
        {
            solve(arr, x + 1, y, n, solAns, path + 'D', paths);
        }

        // Move Right
        if (isSafe(arr, x, y + 1, n))
        {
            solve(arr, x, y + 1, n, solAns, path + 'R', paths);
        }

        // Backtrack
        solAns[x][y] = 0;
    }
}

vector<string> ratInMaze(int **arr, int n)
{
    vector<string> paths;
    string path = "";
    int **solAns = new int *[n];
    for (int i = 0; i < n; i++)
    {
        solAns[i] = new int[n];
        for (int j = 0; j < n; j++)
        {
            solAns[i][j] = 0;
        }
    }
    solve(arr, 0, 0, n, solAns, path, paths);
    for (int i = 0; i < n; i++)
    {
        delete[] solAns[i];
    }
    delete[] solAns;
    return paths;
}

int main()
{
    int n = 4;
    int m[4][4] = {
        {1, 0, 0, 0},
        {1, 1, 0, 1},
        {1, 1, 0, 0},
        {0, 1, 1, 1}};

    int **arr = new int *[n];
    for (int i = 0; i < n; i++)
    {
        arr[i] = new int[n];
        for (int j = 0; j < n; j++)
        {
            arr[i][j] = m[i][j];
        }
    }

    vector<string> paths = ratInMaze(arr, n);

    if (!paths.empty())
    {
        cout << "Output: ";
        for (const string &p : paths)
        {
            cout << p << " ";
        }
        cout << endl;
    }
    else
    {
        cout << "No solution exists" << endl;
    }

    for (int i = 0; i < n; i++)
    {
        delete[] arr[i];
    }
    delete[] arr;

    return 0;
}
