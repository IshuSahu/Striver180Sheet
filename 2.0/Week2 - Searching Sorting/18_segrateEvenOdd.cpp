#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void segregateEvenOdd(vector<int>& arr) {
        int left = 0, right = arr.size() - 1;
        
        while (left <= right) {
            if (arr[left] % 2 == 0) {
                left++;
            } else if (arr[right] % 2 != 0) {
                right--;
            } else {
                swap(arr[left], arr[right]);
                left++;
                right--;
            }
        }
    }
};

int main() {
    Solution sol;
    vector<int> arr = {12, 34, 45, 9, 8, 90, 3};
    sol.segregateEvenOdd(arr);
    
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}
