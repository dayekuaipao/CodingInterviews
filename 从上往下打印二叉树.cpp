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
    vector<int> PrintFromTopToBottom(TreeNode* root) 
    {
        queue<TreeNode*> nodes;
        vector<int> values;
        if(root==nullptr)
            return values;
        nodes.push(root);
        while (!nodes.empty())
        {
            if (nodes.front()->left != nullptr)
            {
                nodes.push(nodes.front()->left);
            }
            if (nodes.front()->right != nullptr)
            {
                nodes.push(nodes.front()->right);
            }
            values.push_back(nodes.front()->val);
            nodes.pop();
        }
        return values;
    }
};