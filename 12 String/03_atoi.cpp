#include <bits/stdc++.h>
using namespace std;

bool isdigit(char ch) {
    return (ch >= '0' && ch <= '9');
}

int myAtoi(string s) {
    int i = 0, n = s.size();
    long result = 0;
    int sign = 1;

    // Step 1: Skip leading whitespaces
    while (i < n && s[i] == ' ') i++;

    // Step 2: Check sign
    if (i < n && (s[i] == '+' || s[i] == '-')) {
        sign = (s[i] == '-') ? -1 : 1;
        i++;
    }

    // Step 3: Read digits using custom isdigit()
    while (i < n && isdigit(s[i])) {
        result = result * 10 + (s[i] - '0');

        // Step 4: Clamp to 32-bit signed int range
        if (sign * result <= INT_MIN) return INT_MIN;
        if (sign * result >= INT_MAX) return INT_MAX;

        i++;
    }

    return sign * result;
}

int main() {
    cout << myAtoi("   -042") << endl;      // -42
    cout << myAtoi("1337c0d3") << endl;     // 1337
    cout << myAtoi("words123") << endl;     // 0
    cout << myAtoi("91283472332") << endl;  // 2147483647 (clamped)
    return 0;
}
