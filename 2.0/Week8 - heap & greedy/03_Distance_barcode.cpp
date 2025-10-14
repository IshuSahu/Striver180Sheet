#include <bits/stdc++.h>
using namespace std;

vector<int> rearrangeBarcodes(vector<int> &barcodes)
{
    unordered_map<int, int> freq;

    // Count frequency of each barcode
    for (int b : barcodes)
    {
        freq[b]++;
    }

    // Max heap based on frequency
    priority_queue<pair<int, int>> maxHeap;
    for (auto &[num, count] : freq)
    {
        maxHeap.push({count, num});
    }

    vector<int> result;

    while (maxHeap.size() >= 2)
    {
        // Get two most frequent elements
        auto [count1, num1] = maxHeap.top();
        maxHeap.pop();
        auto [count2, num2] = maxHeap.top();
        maxHeap.pop();

        // Add them to the result
        result.push_back(num1);
        result.push_back(num2);

        // Decrease frequency and re-add to heap if still available
        if (--count1 > 0)
            maxHeap.push({count1, num1});
        if (--count2 > 0)
            maxHeap.push({count2, num2});
    }

    // If one element left
    if (!maxHeap.empty())
    {
        result.push_back(maxHeap.top().second);
    }

    return result;
}
/*
🧠 How it works:
- Count frequency of each barcode.
- Push all barcodes into a max heap based on frequency.
- Pop the top two elements (most frequent), place them in the result, decrease their count.
- If they still have frequency left, push them back.
- Repeat until the heap is empty.

TC: O(n log k)
SC: O(n + k)
*/

int main()
{
    // Test case 1
    vector<int> barcodes1 = {1, 1, 1, 2, 2, 2};
    vector<int> result1 = rearrangeBarcodes(barcodes1);

    cout << "Rearranged barcodes (Test Case 1): ";
    for (int val : result1)
    {
        cout << val << " ";
    }
    cout << endl;

    // Test case 2
    vector<int> barcodes2 = {1, 1, 1, 1, 2, 2, 3, 3};
    vector<int> result2 = rearrangeBarcodes(barcodes2);

    cout << "Rearranged barcodes (Test Case 2): ";
    for (int val : result2)
    {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}