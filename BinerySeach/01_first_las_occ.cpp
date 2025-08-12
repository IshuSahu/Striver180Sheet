#include <bits/stdc++.h>
using namespace std;

int firstOccurrence(vector<int> &arr, int target) {
    int low = 0, high = arr.size() - 1;
    int ans = -1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == target) {
            ans = mid;         // store answer
            high = mid - 1;    // move left to find earlier occurrence
        }
        else if (arr[mid] < target) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
    return ans;
}

int lastOccurrence(vector<int> &arr, int target) {
    int low = 0, high = arr.size() - 1;
    int ans = -1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == target) {
            ans = mid;         // store answer
            low = mid + 1;     // move right to find later occurrence
        }
        else if (arr[mid] < target) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
    return ans;
}

int main() {
    vector<int> arr = {1, 2, 4, 4, 4, 5, 7, 9};
    int target = 4;

    int first = firstOccurrence(arr, target);
    int last = lastOccurrence(arr, target);

    cout << "First occurrence at index: " << first << "\n";
    cout << "Last occurrence at index: " << last << "\n";

    return 0;
}
