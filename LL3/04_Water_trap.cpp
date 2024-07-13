#include <bits/stdc++.h>

using namespace std;
int trap(vector<int> &arr)
{
    int n = arr.size();

    int waterTrap = 0;
    for (int i = 0; i < n; i++)
    {
        int j = i;
        int leftmax = 0, rightmax = 0;
        while (j > 0)
        {

            leftmax = max(leftmax, arr[j]);
            j--;
        }

        j = i;
        while (j < n)
        {
            rightmax = max(rightmax, arr[j]);
            j++;
        }
        waterTrap += (min(leftmax, rightmax) - arr[i]);
        cout << waterTrap << endl;
    }
    return waterTrap;
}

int trap2(vector<int> &height)
{

    if (height.empty())
        return 0;

    int trap = 0;

    int left = 0;
    int right = height.size() - 1;

    int max1 = height[left];
    int max2 = height[right];

    while (left < right)
        if (max1 < max2)
        {
            trap += max1 - height[left];
            max1 = max(max1, height[++left]);
        }
        else
        {
            trap += max2 - height[right];
            max2 = max(max2, height[--right]);
        }
    return trap;
}
int main()
{
    vector<int> arr;
    arr = {0, 1, 2, 0, 1, 2, 1};
    cout << "The water that can be trapped is " << trap(arr) << endl;
}