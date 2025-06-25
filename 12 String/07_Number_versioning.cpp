#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

// Helper to split by '.'
vector<int> split(string version) {
    vector<int> nums;
    stringstream ss(version);
    string item;

    while (getline(ss, item, '.')) {
        nums.push_back(stoi(item));  // convert to int (ignores leading 0s)
    }

    return nums;
}

int compareVersion(string version1, string version2) {
    vector<int> v1 = split(version1);
    vector<int> v2 = split(version2);

    int n = max(v1.size(), v2.size());

    for (int i = 0; i < n; ++i) {
        int num1 = i < v1.size() ? v1[i] : 0;
        int num2 = i < v2.size() ? v2[i] : 0;

        if (num1 < num2) return -1;
        if (num1 > num2) return 1;
    }

    return 0;
}

int main() {
    cout << compareVersion("1.0.1", "1") << endl;      // Output: 1
    cout << compareVersion("1.01", "1.001") << endl;   // Output: 0
    cout << compareVersion("1.0", "1.0.0") << endl;     // Output: 0
    cout << compareVersion("0.1", "1.1") << endl;       // Output: -1
    return 0;
}
