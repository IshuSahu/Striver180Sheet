#include <bits/stdc++.h>
using namespace std;

class Meeting
{
public:
    int start;
    int end;
    int pos;

    Meeting(int s, int e, int p) : start(s), end(e), pos(p) {}
};

class Solution
{
public:
    static bool comparator(const Meeting &m1, const Meeting &m2)
    {
        if (m1.end < m2.end)
            return true; // lesser than
        else if (m1.end > m2.end)
            return false; // greater than
        else if (m1.pos < m2.pos)
            return true; // on equal of finshed time
        return false;
    }

    void maxMeetings(int s[], int e[], int n)
    {
        vector<Meeting> meetings;
        for (int i = 0; i < n; i++)
        { // O(n)
            meetings.push_back(Meeting(s[i], e[i], i + 1));
        }

        sort(meetings.begin(), meetings.end(), comparator); // O(n(logN))

        vector<int> answer;

        int limit = meetings[0].end;
        answer.push_back(meetings[0].pos);

        for (int i = 1; i < n; i++)
        {
            if (meetings[i].start > limit)
            {
                limit = meetings[i].end;
                answer.push_back(meetings[i].pos);
            }
        }

        cout << "The order in which the meetings will be performed is " << endl;
        for (int i : answer)
        {
            cout << i << " ";
        }
        cout << endl;
    }
};

int main()
{
    Solution obj;
    int n = 6;
    int start[] = {1, 3, 0, 5, 8, 5};
    int end[] = {2, 4, 5, 7, 9, 9};
    obj.maxMeetings(start, end, n);
    return 0;
}
