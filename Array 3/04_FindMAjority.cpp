// Majority Elements(&gt;N/3 times) | Find the elements that appears more than N/3 times in the array
// Input Format
// N = 6, array[] = {11,33,33,11,33,11}
// 11 33


/*

we are fully sure that it will take At max 2 element in array element which is > n/3

*/
#include <bits/stdc++.h>

using namespace std;

int majorityElement(vector<int> &arr)
{
    int n = arr.size();
    vector<int> ls;
    for (int i = 0; i < n; i++)
    {
        if (ls.size() == 0 || ls[0] != arr[i])
        {

            int cnt = 0;
            for (int j = 0; j < n; j++)
            {
                if (arr[i] == arr[j])
                {
                    cnt++;
                }
            }
            if (cnt > n / 3)
                ls.push_back(arr[i]);
        }
    }

    cout << ls[0] << " " << ls[1] << endl;
    return -1;
}
int majorityElement1(vector<int> &arr) // O(n*logN)
{
    int n = arr.size();
    map <int,int> mp;
    vector<int> ls;
    for (int i = 0; i < n; i++) // N
    {
        mp[arr[i]]++; //(lonN)
    }

    for(auto it:mp){
        if(it.second > n/3) ls.push_back(it.first);
    }

    cout << ls[0] << " " << ls[1] << endl;
    return -1;
}

int majorityElement2(vector<int> v) {
    int n = v.size(); //size of the array

    int cnt1 = 0, cnt2 = 0; // counts
    int el1 = INT_MIN; // element 1
    int el2 = INT_MIN; // element 2

    // applying the Extended Boyer Moore's Voting Algorithm:
    for (int i = 0; i < n; i++) {
        if (cnt1 == 0 && el2 != v[i]) {
            cnt1 = 1;
            el1 = v[i];
        }
        else if (cnt2 == 0 && el1 != v[i]) {
            cnt2 = 1;
            el2 = v[i];
        }
        else if (v[i] == el1) cnt1++;
        else if (v[i] == el2) cnt2++;
        else {
            cnt1--, cnt2--;
        }
    }

    vector<int> ls; // list of answers

    // Manually check if the stored elements in
    // el1 and el2 are the majority elements:
    cnt1 = 0, cnt2 = 0;
    for (int i = 0; i < n; i++) {
        if (v[i] == el1) cnt1++;
        if (v[i] == el2) cnt2++;
    }

    int mini = int(n / 3) + 1; //imp
    if (cnt1 >= mini) ls.push_back(el1);
    if (cnt2 >= mini) ls.push_back(el2);

    // Uncomment the following line
    // if it is told to sort the answer array:
    // sort(ls.begin(), ls.end()); //TC --> O(2*log2) ~ O(1);
    cout << ls[0] << " " << ls[1] << endl;
    return -1;
}

int main()
{
    vector<int> arr = {3, 3, 3, 4, 2, 4, 4, 4, 3, 2, 4};
    // int ans = majorityElement(arr);
    // int ans = majorityElement1(arr);
    int ans = majorityElement2(arr);
    cout << "The majority element is: " << ans << endl;
    return 0;
}