#include <bits/stdc++.h>
using namespace std;

// Function to calculate factorial of a number
long long factorial(int n)
{
    long long fact = 1;
    for (int i = 1; i <= n; ++i)
    {
        fact *= i;
    }
    return fact;
}

// M-1 Function to calculate the Catalan number C_k
long long catalan(int k)
{
    // C_k = (2k)! / (k! * (k + 1)!)
    long long fact2k = factorial(2 * k);
    long long factk = factorial(k);
    long long factk1 = factorial(k + 1);
    return fact2k / (factk * factk1);
}

// M-2
long long countHandshakes(int N)
{
    // Base case: If there are no people or just one pair, there's exactly 1 way to form handshakes
    if (N == 0 || N == 2)
    {
        return 1;
    }

    long long totalWays = 0;

    // Iterate over all possible pairings for the first person
    for (int k = 2; k <= N; k += 2)
    { // k must be even to avoid crossing
        // Count handshakes for the left and right groups
        totalWays += countHandshakes(k - 2) * countHandshakes(N - k);
    }

    return totalWays;
}

// M-3
int count(int N)
{
    vector<int> dp(N + 1, 0);
    dp[0] = 1;
    for (int i = 2; i <= N; i += 2)
    {
        for (int j = 0; j <= i - 1; j += 2)
        {
            dp[i] += dp[j] * dp[i - 2 - j];
        }
    }
    return dp[N];
}

int main()
{
    int N; // Number of people

    cout << "Enter the number of people (even number): ";
    cin >> N;

    if (N % 2 != 0)
    {
        cout << "N must be an even number!" << endl;
    }
    else
    {
        int k = N / 2;
        long long result = catalan(k);
        cout << "The number of ways to make non-crossing handshakes is: " << result << endl;
        cout << "The number of ways to make non-crossing handshakes is: " << countHandshakes(N) << endl;
        cout << "The number of ways to make non-crossing handshakes is: " << count(N) << endl;
    }

    return 0;
}
