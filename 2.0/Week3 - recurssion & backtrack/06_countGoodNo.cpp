/*
Observations:
For n = 1, the answer is simply 5 (since there is only one index, and it must be even).
For n = 2, the number of good strings is 5 choices for the first position and 4 choices for the second.
For n = 3, the first and third positions can each be chosen from the 5 even digits, while the second
*/

#include <iostream>
using namespace std;

const int MOD = 1e9 + 7; //1e9 ==>10^9

class Solution
{
public:
    int countGoodStrings(long long n)
    {
        long long even_count = (n + 1) / 2;
        long long odd_count = n / 2;

        long long even_part = 1;
        for (long long i = 0; i < even_count; ++i)
        {
            even_part = (even_part * 5) % MOD;
        }

        long long odd_part = 1;
        for (long long i = 0; i < odd_count; ++i)
        {
            odd_part = (odd_part * 4) % MOD;
        }

        return (even_part * odd_part) % MOD;
    }
};

int main()
{
    Solution solution;
    cout << solution.countGoodStrings(1) << endl;
    cout << solution.countGoodStrings(4) << endl;
    cout << solution.countGoodStrings(50) << endl;
    return 0;
}
