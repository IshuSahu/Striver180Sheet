#include <bits/stdc++.h>

using namespace std;
/*
INTUITION
This is essentially a greedy + binary search + multiset optimization problem.
*/
class Solution
{
public:
    // Check if it's possible to assign `w` tasks
    bool possible(int w, vector<int> &workers, vector<int> &tasks, int pills, int strength)
    {
        if (w > workers.size())
            return false;

        multiset<int> taskSet(tasks.begin(), tasks.begin() + w);
        multiset<int> workerSet(workers.end() - w, workers.end());

        while (!taskSet.empty())
        {
            int task = *taskSet.rbegin(); // get the hardest remaining task
            taskSet.erase(prev(taskSet.end()));

            auto it = workerSet.lower_bound(task);
            if (it != workerSet.end())
            {
                // Worker can do the task directly
                workerSet.erase(it);
            }
            else
            {
                // Try to assign a pill to the weakest worker
                if (pills <= 0)
                    return false;
                int boosted = task - strength;
                auto weakest = workerSet.lower_bound(boosted);
                if (weakest == workerSet.end())
                    return false;
                workerSet.erase(weakest);
                pills--;
            }
        }

        return true;
    }

    int maxTaskAssign(vector<int> &tasks, vector<int> &workers, int pills, int strength)
    {
        sort(tasks.begin(), tasks.end());
        sort(workers.begin(), workers.end());

        int low = 0, high = min((int)tasks.size(), (int)workers.size());
        int answer = 0;

        while (low <= high)
        {
            int mid = (low + high) / 2;
            if (possible(mid, workers, tasks, pills, strength))
            {
                answer = mid;
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }

        return answer;
    }
};

int main()
{
    vector<int> tasks = {3, 9, 8};
    vector<int> workers = {7, 3, 5};
    int pills = 1;
    int strength = 4;

    Solution sol;
    int maxTasks = sol.maxTaskAssign(tasks, workers, pills, strength);

    cout << "Maximum number of tasks that can be assigned: " << maxTasks << endl;

    return 0;
}