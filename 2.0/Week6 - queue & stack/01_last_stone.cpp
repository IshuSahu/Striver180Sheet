/*
Problem Explanation: Last Stone Weight
You're given a list of stone weights. You repeatedly smash the two heaviest stones together. The rules are:
- If the two stones are the same weight, both are destroyed.
- If they're different, the lighter one is destroyed, and the heavier one becomes (heavier - lighter).

Process:
Pick 7 and 8 → 8 - 7 = 1, stones = [2,4,1,1,1]
Pick 4 and 2 → 4 - 2 = 2, stones = [2,1,1,1]
Pick 2 and 1 → 2 - 1 = 1, stones = [1,1,1]
Pick 1 and 1 → both destroyed, stones = [1]
*/

// Brut Force
#include <bits/stdc++.h>
using namespace std;

int lastStoneWeight(vector<int> &stones)
{
    while (stones.size() > 1)
    {
        sort(stones.begin(), stones.end(), greater<int>());
        int y = stones[0];
        int x = stones[1];
        stones.erase(stones.begin()); // remove y
        stones.erase(stones.begin()); // remove x
        if (x != y)
        {
            stones.push_back(y - x);
        }
    }
    return stones.empty() ? 0 : stones[0];
}
// TC: O(n² log n) in worst case

//OPTIMUM APPROCH
//Use a max-heap (priority queue) to always access the 2 largest stones quickly (O(log n)).
int lastStoneWeightOP(vector<int> &stones)
{
    priority_queue<int> maxHeap(stones.begin(), stones.end());

    while (maxHeap.size() > 1)
    {
        int y = maxHeap.top();
        maxHeap.pop();
        int x = maxHeap.top();
        maxHeap.pop();

        if (x != y)
        {
            maxHeap.push(y - x);
        }
    }

    return maxHeap.empty() ? 0 : maxHeap.top();
}

int main() {
    vector<int> stones = {2,7,4,1,8,1};

    int result = lastStoneWeightOP(stones);
    cout << "Last stone weight: " << result << endl;

    return 0;
}