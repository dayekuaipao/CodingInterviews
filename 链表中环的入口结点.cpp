/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
};
*/
class Solution {
public:
    int FindLoopCount(ListNode* pHead)
    {
        int count = 0;
        if (pHead == nullptr)
        {
            return -1;
        }
        else
        {
            ListNode* iter1 = pHead;
            ListNode* iter2 = pHead;
            while (true)
            {
                if (iter1 != nullptr)
                {
                    iter1 = iter1->next;
                }
                else
                {
                    return -1;
                }
                if (iter1 != nullptr)
                {
                    iter1 = iter1->next;
                }
                else
                {
                    return -1;
                }
                iter2 = iter2->next;
                ++count;
                if (iter1 == iter2)
                {
                    return count;
                }   
            }
        }
    }
    ListNode* EntryNodeOfLoop(ListNode* pHead)
    {
        int count = FindLoopCount(pHead);
        if (count == -1)
        {
            return nullptr;
        }
        else
        {
            ListNode* iter1 = pHead;
            ListNode* iter2 = pHead;
            for (int i = 0; i < count; ++i)
            {
                iter1 = iter1->next;
            }
            while (iter1 != iter2)
            {
                iter1 = iter1->next;
                iter2 = iter2->next;
            }
            return iter1;
        }
    }
};