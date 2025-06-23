#include <bits/stdc++.h>
using namespace std;

int romanToInt(string s) {
    unordered_map<char, int> roman = {
        {'I', 1}, {'V', 5}, {'X', 10},
        {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}
    };

    int result = 0;
    for (int i = 0; i < s.length(); i++) {
        //If current < next → subtract current else add
        if (i + 1 < s.length() && roman[s[i]] < roman[s[i + 1]]) { 
            result -= roman[s[i]];
        } else {
            result += roman[s[i]];
        }
    }
    return result;
}

string intToRoman(int num) {
    vector<pair<int, string>> val = {
        {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"},
        {100,  "C"}, {90,  "XC"}, {50,  "L"}, {40,  "XL"},
        {10,   "X"}, {9,   "IX"}, {5,   "V"}, {4,   "IV"},
        {1,    "I"}
    };

    string result = "";
    for (auto &p : val) {
        while (num >= p.first) {
            result += p.second;
            num -= p.first;
        }
    }
    return result;
}

int main() {
    string roman = "MCMXCIV"; // 1994
    cout << "Roman to Integer: " << romanToInt(roman) << endl;
    cout << "Roman to Integer: " << intToRoman(1992) << endl;
    return 0;
}
