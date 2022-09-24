/*
struct TreeLinkNode {
    int val;
    struct TreeLinkNode *left;
    struct TreeLinkNode *right;
    struct TreeLinkNode *next;
    TreeLinkNode(int x) :val(x), left(NULL), right(NULL), next(NULL) {
         
    }
};
*/
class Solution {
public:
    TreeLinkNode* GetNext(TreeLinkNode* pNode)
    {
        if (pNode == nullptr)
        {
            return nullptr;
        }
        else if (pNode->right != nullptr)
        {
            TreeLinkNode* tmp = pNode->right;
            while (tmp->left != nullptr)
            {
                tmp = tmp->left;
            }
            return tmp;
        }
        else
        {
            TreeLinkNode* tmp = pNode;
            while (tmp->next !=nullptr&&tmp->next->right == tmp)
            {
                tmp = tmp->next;
            }
            return tmp->next;
        }
    }
};
