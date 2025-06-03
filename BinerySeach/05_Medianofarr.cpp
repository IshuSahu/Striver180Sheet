#include <bits/stdc++.h>
using namespace std;

double median(vector<int> &a, vector<int> &b)
{
    int n1 = a.size(), n2 = b.size();

    vector<int> arr3;
    int i = 0, j = 0;
    while (i < n1 && j < n2)
    {
        if (a[i] < b[j])
            arr3.push_back(a[i++]);
        else
            arr3.push_back(b[j++]);
    }

    while (i < n1)
        arr3.push_back(a[i++]);
    while (j < n2)
        arr3.push_back(b[j++]);

    int n = n1 + n2;
    if (n % 2 == 1)
    {
        return (double)arr3[n / 2];
    }
    else
    {
        return ((double)arr3[n / 2] + (double)arr3[(n / 2) - 1]) / 2.0;
    }
}
/*
Time Complexity: O(n1+n2)
Space Complexity: O(n1+n2)
*/

double median1_2(vector<int>& a, vector<int>& b) {
    //size of two given arrays:
    int n1 = a.size(), n2 = b.size();
    int n = n1 + n2; //total size
    //required indices:
    int ind2 = n / 2;
    int ind1 = ind2 - 1;
    int cnt = 0;
    int ind1el = -1, ind2el = -1;

    //apply the merge step:
    int i = 0, j = 0;
    while (i < n1 && j < n2) {
        if (a[i] < b[j]) {
            if (cnt == ind1) ind1el = a[i];
            if (cnt == ind2) ind2el = a[i];
            cnt++;
            i++;
        }
        else {
            if (cnt == ind1) ind1el = b[j];
            if (cnt == ind2) ind2el = b[j];
            cnt++;
            j++;
        }
    }

    //copy the left-out elements:
    while (i < n1) {
        if (cnt == ind1) ind1el = a[i];
        if (cnt == ind2) ind2el = a[i];
        cnt++;
        i++;
    }
    while (j < n2) {
        if (cnt == ind1) ind1el = b[j];
        if (cnt == ind2) ind2el = b[j];
        cnt++;
        j++;
    }

    //Find the median:
    if (n % 2 == 1) {
        return (double)ind2el;
    }

    return (double)((double)(ind1el + ind2el)) / 2.0;
}
/*
Time Complexity: O(n1+n2)
Space Complexity: O(1)
*/

//using Bineray search
double median2(vector<int>& nums1, vector<int>& nums2) {
    if (nums1.size() > nums2.size()) {
        return median2(nums2, nums1);  // Always binary search on smaller array
    }

    int n1 = nums1.size();
    int n2 = nums2.size();
    int low = 0, high = n1;

    while (low <= high) {
        int cut1 = (low + high) / 2;
        int cut2 = (n1 + n2 + 1) / 2 - cut1;

        int left1 = (cut1 == 0) ? INT_MIN : nums1[cut1 - 1];
        int left2 = (cut2 == 0) ? INT_MIN : nums2[cut2 - 1];

        int right1 = (cut1 == n1) ? INT_MAX : nums1[cut1];
        int right2 = (cut2 == n2) ? INT_MAX : nums2[cut2];

        if (left1 <= right2 && left2 <= right1) {
            if ((n1 + n2) % 2 == 0)
                return (max(left1, left2) + min(right1, right2)) / 2.0;
            else
                return max(left1, left2);
        } else if (left1 > right2) {
            high = cut1 - 1;
        } else {
            low = cut1 + 1;
        }
    }

    return 0.0;  // Should never reach here
}
int main()
{
    vector<int> a = {1, 4, 7, 10, 12};
    vector<int> b = {2, 3, 6, 9};
    cout << "The median of two sorted array is " << fixed << setprecision(1)
         << median2(a, b) << '\n';
}
