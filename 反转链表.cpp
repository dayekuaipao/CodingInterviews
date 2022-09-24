/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
            val(x), next(NULL) {
    }
};*/
class Solution {
public:
    ListNode* ReverseList(ListNode* pHead)
    {
        ListNode* before = nullptr;
        ListNode* iter = pHead;
        while (iter != nullptr)
        {
            ListNode* next = iter->next;
            iter->next = before;
            before = iter;
            iter = next;
        }
        return before;
    }
};
