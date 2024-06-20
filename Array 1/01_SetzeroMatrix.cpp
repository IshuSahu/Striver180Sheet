#include <bits/stdc++.h>

using namespace std;

void MarkRow(vector<vector<int>> &Matrix, int n, int m, int i)
{
    for (int k = 0; k < m; k++)
    {
        if (Matrix[i][k] != 0)
        {
            Matrix[i][k] = -1;
        }
    }
}
void Markcol(vector<vector<int>> &Matrix, int n, int m, int j)
{
    for (int k = 0; k < n; k++)
    {
        if (Matrix[k][j] != 0)
        {
            Matrix[k][j] = -1;
        }
    }
}
vector<vector<int>> zeroMatrix(vector<vector<int>> &Matrix, int n, int m)
{
    //Brute
    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < m; j++)
    //     {
    //         if (Matrix[i][j] == 0)
    //         {
    //             MarkRow(Matrix, n, m, i);
    //             Markcol(Matrix, n, m, j);
    //         }
    //     }
    // }
    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < m; j++)
    //     {
    //         if (Matrix[i][j] == -1)
    //         {
    //             Matrix[i][j] = 0;
    //         }
    //     }
    // }


    // Optimal
    int row[n] ={0};
    int col[m] ={0};
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (Matrix[i][j] == 0)
            {
               row[i]=1;
               col[j]=1;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if(row[i] || col[j]){
                Matrix[i][j] = 0;
            }
        }
    }
    return Matrix;
}
int main()
{
    vector<vector<int>> matrix = {{1, 1, 1, 1}, {1, 0, 1, 0}, {1, 1, 1, 1}};
    int n = matrix.size();    // rows
    int m = matrix[0].size(); // col
    vector<vector<int>> ans = zeroMatrix(matrix, n, m);

    cout << "The Final matrix is: n \n";
    for (auto it : ans)
    {
        for (auto ele : it)
        {
            cout << ele << " ";
        }
        cout << "\n";
    }
    return 0;
}