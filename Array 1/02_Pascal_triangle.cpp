
// #include <bits/stdc++.h>
// using namespace std;

// int nCr(int n, int r) {
//     long long res = 1;

//     // calculating nCr:
//     for (int i = 0; i < r; i++) {
//         res = res * (n - i);
//         res = res / (i + 1);
//     }
//     return res;
// }

// int pascalTriangle(int r, int c) {
//     int element = nCr(r - 1, c - 1);
//     return element;
// }

// int main()
// {
//     // Given row number r and column number c. Print the element at position (r, c) in Pascal’s triangle.
//     int r = 5; // row number
//     int c = 3; // col number
//     int element = pascalTriangle(r, c);
//     cout << "The element at position (r,c) is: "
//             << element << "n";
//     return 0;
// }

#include <iostream>

using namespace std;
int pascal(int i, int j)
{
    if (j == 0 || j == i)
    {
        return 1;
    }
    else
    {
        return pascal(i - 1, j - 1) + pascal(i - 1, j);
    }
}
int factorial(int num)
{
    int fact = 1;
    while (num >= 1)
    {
        fact = fact * num;
        num--;
    }
    return fact;
}
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            cout << pascal(i, j) << " ";
        }
        cout << endl;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            int value = factorial(i) / (factorial(i - j) * factorial(j));
            cout << value << " ";
        }
        cout << endl;
    }

    return 0;
}