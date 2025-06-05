/*
Problem: Maximum Sum Combination (K largest sums from two arrays)
You are given two integer arrays A and B of size N, and an integer K.

Task:
Find the K maximum sum combinations from all the possible pairs formed by taking one element from A and one from B.

Input:
A = [1, 4, 2, 3]
B = [2, 5, 1, 6]
K = 4

All possible sums:
(4,6)=10, (4,5)=9, (3,6)=9, (4,2)=6, (3,5)=8, ...

Top 4 sums = [10, 9, 9, 8]
Output: [10, 9, 9, 8]

*/
#include <bits/stdc++.h>
using namespace std;

vector<int> bruteForceMaxSumCombinations(vector<int>& A, vector<int>& B, int K) {
    int n = A.size();
    vector<int> allSums;

    // Generate all combinations
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            allSums.push_back(A[i] + B[j]);
        }
    }

    // Sort in descending order
    sort(allSums.begin(), allSums.end(), greater<int>());

    // Take the first K elements
    vector<int> result;
    for (int i = 0; i < K && i < allSums.size(); ++i) {
        result.push_back(allSums[i]);
    }

    return result;
}
/*
TC: O(N² log N)
SC: O(N²)


*/

vector<int> kMaxSumCombinations(vector<int>& A, vector<int>& B, int K) {
    int N = A.size();
    sort(A.begin(), A.end(), greater<int>());
    sort(B.begin(), B.end(), greater<int>());

    // Max-heap with sum, i, j
    priority_queue<tuple<int, int, int>> maxHeap;
    set<pair<int, int>> visited;

    maxHeap.push(make_tuple(A[0] + B[0], 0, 0));
    visited.insert({0, 0});

    vector<int> result;

    while (K-- && !maxHeap.empty()) {
        tuple<int, int, int> top = maxHeap.top();
        maxHeap.pop();

        int sum = get<0>(top);
        int i = get<1>(top);
        int j = get<2>(top);
        result.push_back(sum);

        if (i + 1 < N && visited.find({i + 1, j}) == visited.end()) {
            maxHeap.push(make_tuple(A[i + 1] + B[j], i + 1, j));
            visited.insert({i + 1, j});
        }

        if (j + 1 < N && visited.find({i, j + 1}) == visited.end()) {
            maxHeap.push(make_tuple(A[i] + B[j + 1], i, j + 1));
            visited.insert({i, j + 1});
        }
    }

    return result;
}
/*
TC: O(K * log K)
SC: O(K)

*/
int main() {
    vector<int> A = {1, 4, 2, 3};
    vector<int> B = {2, 5, 1, 6};
    int K = 4;

    vector<int> res = kMaxSumCombinations(A, B, K);
    for (int sum : res)
        cout << sum << " ";
    cout << endl;

    return 0;
}
