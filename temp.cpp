#include <iostream>
#include <vector>
#include <utility>

using namespace std;

bool isCrossing(pair<int, int> p1, pair<int, int> p2) {
    return (p1.first < p2.first && p1.second > p2.second) || (p1.first > p2.first && p1.second < p2.second);
}

bool isValidHandshakeCombination(vector<pair<int, int>>& handshakes) {
    for (int i = 0; i < handshakes.size(); i++) {
        for (int j = i + 1; j < handshakes.size(); j++) {
            if (isCrossing(handshakes[i], handshakes[j])) {
                return false;
            }
        }
    }
    return true;
}

int bruteForceHandshake(int N) {
    vector<pair<int, int>> allHandshakes;
    return countValidHandshakes(allHandshakes);
}

int count(int N) {
    vector<long long> dp(N / 2 + 1, 0);
    dp[0] = 1;
    
    for (int i = 1; i <= N / 2; i++) {
        for (int j = 0; j < i; j++) {
            dp[i] += dp[j] * dp[i - j - 1];
        }
    }
    
    return dp[N / 2];
}

int main() {
    int N;
    cin >> N;
    cout << count(N) << endl;
    return 0;
}
