#include <iostream>
#include <string>
using namespace std;

string countAndSay(int n) {
    if (n == 1) return "1";

    string prev = "1";

    for (int i = 2; i <= n; ++i) { //as 1 is already handle so you to start from 2 
        string curr = "";
        int count = 1;

        for (int j = 1; j < prev.size(); ++j) {
            if (prev[j] == prev[j - 1]) {
                count++; // count repeating digits
            } else {
                curr += to_string(count) + prev[j - 1];
                count = 1;
            }
        }

        // add the last group
        curr += to_string(count) + prev.back();

        prev = curr;
    }

    return prev;
}

int main() {
    int n = 5;
    cout << "Count and Say (" << n << "): " << countAndSay(n) << endl; // Output: "1211"
    return 0;
}
