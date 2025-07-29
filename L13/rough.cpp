/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
public:
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        ListNode *ans = NULL;

        if (list1 == NULL)
        {
            return list2;
        }
        if (list2 == NULL)
        {
            return list1;
        }

        while (list1 != NULL && list2 != NULL)
        {
            if (list1->val < list2->val)
            {
                if (ans == NULL)
                {
                    ans = list1;
                    list1 = list1->next;
                    ans->next = NULL;
                }
                else
                {
                    ListNode *t = ans;
                    while (t->next != NULL)
                    {
                        t = t->next;
                    }
                    t->next = list1;
                    list1 = list1->next;
                    t->next->next = NULL;
                }
            }
            else
            {
                if (ans == NULL)
                {
                    ans = list2;
                    list2 = list2->next;
                    ans->next = NULL;
                }
                else
                {
                    ListNode *t = ans;
                    while (t->next != NULL)
                    {
                        t = t->next;
                    }
                    t->next = list2;
                    list2 = list2->next;
                    t->next->next = NULL;
                }
            }
        }

        if (list1 != NULL)
        {
            ListNode *t = ans;
            while (t->next != NULL)
            {
                t = t->next;
            }
            t->next = list1;
            list1 = list1->next;
            t->next->next = NULL;
        }
        if (list2 != NULL)
        {
            ListNode *t = ans;
            while (t->next != NULL)
            {
                t = t->next;
            }
            t->next = list1;
            list1 = list1->next;
            t->next->next = NULL;
        }
    }
};