/*
struct RandomListNode {
    int label;
    struct RandomListNode *next, *random;
    RandomListNode(int x) :
            label(x), next(NULL), random(NULL) {
    }
};
*/
class Solution {
public:
void CloneNode(RandomListNode* pHead)
{
    RandomListNode* iter = pHead;
    while (iter != nullptr)
    {
        RandomListNode* cloneNode = new RandomListNode(iter->label);
        cloneNode->next = iter->next;
        cloneNode->random = iter->random;
        iter->next = cloneNode;
        iter = cloneNode->next;
    }
    RandomListNode* clone = pHead;
}
void ChangeRandomNode(RandomListNode* pHead)
{
    RandomListNode* iter = pHead->next;
    while (iter != nullptr)
    {
        if (iter->random != nullptr)
        {
            iter->random = iter->random->next;
        }
        if (iter->next == nullptr)
        {
            break;
        }
        else
        {
            iter = iter->next->next;
        }
    }
    RandomListNode* clone = pHead;
}
RandomListNode* SplitList(RandomListNode* pHead)
{
    RandomListNode* iter1 = pHead;
    RandomListNode* head2 = pHead->next;
    RandomListNode* iter2 = head2;
    int count = 0;
    while (iter1 != nullptr)
    {
        iter1->next = iter1->next->next;
        if (iter2->next != nullptr)
        {
            iter2->next = iter2->next->next;
        }
        else
        {
            iter2->next = nullptr;
        }
        iter1 = iter1->next;
        iter2 = iter2->next;
    }
    return head2;
}

    RandomListNode* Clone(RandomListNode* pHead)
    {
        if(pHead!=nullptr)
        {
        CloneNode(pHead);
        ChangeRandomNode(pHead);
        return SplitList(pHead);
        }
        else{
            return nullptr;
        }
    }
};