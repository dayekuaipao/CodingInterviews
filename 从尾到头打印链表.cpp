/**
*  struct ListNode {
*        int val;
*        struct ListNode *next;
*        ListNode(int x) :
*              val(x), next(NULL) {
*        }
*  };
*/
class Solution {
public:
    vector<int> printListFromTailToHead(ListNode* head) {
        vector<int> v;
        stack<int> s;
        ListNode* node = head;
        while (node != nullptr)
        {
            s.push(node->val);
            node = node->next;
        }
        while (!s.empty())
        {
            int tmp = s.top();
            s.pop();
            v.push_back(tmp);
 
        }
        return v;
    }
};