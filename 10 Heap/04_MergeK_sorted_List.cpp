#include <bits/stdc++.h>

using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution
{
public:
    ListNode *merge(ListNode *list1, ListNode *list2)
    {

        // initialising result node
        ListNode *res = new ListNode(0);
        ListNode *tail = res;

        while (list1 != NULL && list2 != NULL)
        {

            if (list1->val <= list2->val)
            {
                tail->next = list1;
                list1 = list1->next;
            }
            else
            {
                tail->next = list2;
                list2 = list2->next;
            }
            tail = tail->next;
        }

        if (list1 == NULL)
            tail->next = list2;
        else
            tail->next = list1;

        return res->next;
    }

    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        ListNode *res = new ListNode(0);

        for (ListNode *list : lists)
        {
            res->next = merge(res->next, list);
        }

        return res->next;
    }
    /*
     TC: O(K*N)
     SC: O(1)
    */
};