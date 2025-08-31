#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int minCostClimbingStairs(vector<int> &cost)
{
    int n = cost.size();
    int prev = 0;
    int curr = 0;
    for (int i = 2; i <= n; i++)
    {
        int next = min(curr + cost[i-1], prev + cost[i-2]);
        prev = curr;
        curr = next;
    }
    return curr;
}

int main()
{
    vector<int> cost = {10, 15, 20};
    cout << "Minimum cost to reach the top: " << minCostClimbingStairs(cost) << endl;

    vector<int> cost2 = {1, 100, 1, 1, 1, 100, 1, 1, 100, 1};
    cout << "Minimum cost to reach the top: " << minCostClimbingStairs(cost2) << endl;

    return 0;
}
