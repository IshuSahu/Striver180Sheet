/*
Given an array of positive integers. Your task is to rearrange the array elements alternatively i.e. first element should be the max value, the second should be the min value, the third should be the second max, the fourth should be the second min, and so on.
Note: Modify the original array itself. Do it without using any extra space. You do not have to return anything.
*/

#include <iostream>
#include <vector>
using namespace std;

void rearrange(vector<int>& arr) {
    int n = arr.size();
    int maxIdx = n - 1, minIdx = 0;
    int maxElem = arr[n - 1] + 1; // Must be greater than any element in array

    for (int i = 0; i < n; ++i) {
        if (i % 2 == 0) {
            arr[i] += (arr[maxIdx] % maxElem) * maxElem;
            maxIdx--;
        } else {
            arr[i] += (arr[minIdx] % maxElem) * maxElem;
            minIdx++;
        }
    }

    // Final step: decode values
    for (int i = 0; i < n; ++i)
        arr[i] /= maxElem;
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 5, 6};
    rearrange(arr);
    for (int x : arr)
        cout << x << " ";
    return 0;
}

/*
✅ Idea:

Use an encoding trick to store two values at each index using modulus arithmetic.

🤯 How?

Since all elements are positive and array is sorted:

Let maxElem = arr[n-1] + 1 (any number > all elements)
At each index, encode both:
old value = arr[i] % maxElem
new value = (newValue % maxElem) * maxElem

Formula:
    arr[i] = arr[i] + (newValue % maxElem) * maxElem;
    arr[i] = arr[i] / maxElem;
*/