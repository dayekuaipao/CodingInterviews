/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};*/
class Solution {
public:
   void ConvertCore(TreeNode* pNodeOfTree, TreeNode* & last)
{
    if (pNodeOfTree == nullptr)
    {
        return;
    }
    if (pNodeOfTree->left != nullptr)
    {
        ConvertCore(pNodeOfTree->left,last);
    }
    if (last != nullptr)
    {
        last->right = pNodeOfTree;
        pNodeOfTree->left = last;
        last = pNodeOfTree;
    }
    else
    {
        last = pNodeOfTree;
    }
    cout << last->val << " ";
    if (pNodeOfTree->right != nullptr)
    {
        ConvertCore(pNodeOfTree->right, last);
    }
}
TreeNode* Convert(TreeNode* pRootOfTree)
{;
    if (pRootOfTree != nullptr)
    {
        TreeNode* last = nullptr;
        ConvertCore(pRootOfTree, last);
        TreeNode* head = pRootOfTree;
        while (head->left != nullptr)
        {
            head = head->left;
        }
        return head;
    }
    else
    {
        return nullptr;
    }
}
};