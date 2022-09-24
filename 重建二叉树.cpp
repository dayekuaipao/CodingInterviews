/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* reConstructBinaryTreeCore(vector<int>::const_iterator pstart, vector<int>::const_iterator pend, vector<int>::const_iterator vstart, vector<int>::const_iterator vend)
    {
        TreeNode* newTreeNode = new TreeNode(*pstart);
        vector<int>::const_iterator vindex = find(vstart, vend, *pstart);
        cout << (*vindex) << " ";
        if (vindex == vend)
        {
            return nullptr;
        }
        if (vindex != vstart)
        {
            newTreeNode->left = reConstructBinaryTreeCore(pstart + 1, pstart + 1 + (vindex - vstart), vstart, vindex);
        }
        if (vindex != vend - 1)
        {
            newTreeNode->right = reConstructBinaryTreeCore(pstart + 1 + (vindex - vstart), pend, vindex + 1, vend);
        }
        return newTreeNode;
    }
 
    TreeNode* reConstructBinaryTree(const vector<int> pre, const vector<int> vin) {
        return reConstructBinaryTreeCore(pre.begin(), pre.end(), vin.begin(), vin.end());
    }
};