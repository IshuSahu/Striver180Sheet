#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        sort(points.begin(), points.end(), [](const vector<int>& a, const vector<int>& b) {
            int distA = a[0] * a[0] + a[1] * a[1];
            int distB = b[0] * b[0] + b[1] * b[1];
            return distA < distB;
        });

        vector<vector<int>> result(points.begin(), points.begin() + k);
        return result;
    }
};

int main() {
    vector<vector<int>> points = {{3, 3}, {5, -1}, {-2, 4}};
    int k = 2;

    Solution sol;
    vector<vector<int>> closestPoints = sol.kClosest(points, k);

    cout << "The " << k << " closest points to the origin are:" << endl;
    for (const auto& point : closestPoints) {
        cout << "[" << point[0] << ", " << point[1] << "]" << endl;
    }

    return 0;
}
