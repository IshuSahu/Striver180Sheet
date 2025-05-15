#include <bits/stdc++.h>

using namespace std;
void findDuplicate(vector<int> v)
{
    int n = v.size();
    int arr[n + 1] = {0};
    int miss = -1, dupli = -1;
    for (int i = 0; i < n; i++)
    {
        arr[v[i]]++;
    }
    for (int i = 1; i <= n; i++)
    {
        if (arr[i] == 0)
        {
            miss = i;
        }
        if (arr[i] == 2)
        {
            dupli = i;
        }
        if (miss != -1 && dupli != -1)
        {
            cout << "misss " << miss << endl;
            cout << "dupli " << dupli << endl;
            return;
        }
    }
    cout << "misss " << miss << endl;
    cout << "dupli " << dupli << endl;
}
int main()
{
    vector<int> arr;
    arr = {1, 3, 4, 2, 5, 3};
    // arr = {1, 1,1,1,1};
    findDuplicate(arr);
    return 0;
}