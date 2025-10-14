#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int eraseOverlapIntervals(vector<vector<int>> &intervals)
    {
        if (intervals.empty()) return 0;

        // Sort by end time
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });

        int count = 1; // At least one interval is selected
        int lastEnd = intervals[0][1];

        for (int i = 1; i < intervals.size(); ++i)
        {
            if (intervals[i][0] >= lastEnd)
            {
                // Non-overlapping, include it
                count++;
                lastEnd = intervals[i][1];
            }
        }

        return intervals.size() - count;
    }
};

int main()
{
    vector<vector<int>> intervals = {
        {1, 2},
        {2, 3},
        {3, 4},
        {1, 3}
    };

    Solution sol;
    int result = sol.eraseOverlapIntervals(intervals);

    cout << "Minimum intervals to remove: " << result << endl;

    return 0;
}
