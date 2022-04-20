/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};
*/
class Solution {
public:
    vector<vector<int> > Print(TreeNode* pRoot) {
        stack<TreeNode*> stack1;
        stack<TreeNode*> stack2;
        vector<vector<int>> v;
        if(pRoot==nullptr)
            return v;
        stack1.push(pRoot);
        while (!stack1.empty() || !stack2.empty())
        {
            vector<int> vv1;
            while (!stack1.empty())
            {
                if (stack1.top()->left != nullptr)
                    stack2.push(stack1.top()->left);
                if (stack1.top()->right != nullptr)
                    stack2.push(stack1.top()->right);
                vv1.push_back(stack1.top()->val);
                stack1.pop();
            }
            if(!vv1.empty())
                v.push_back(vv1);
            vector<int> vv2;
            while (!stack2.empty())
            {
                if (stack2.top()->right != nullptr)
                    stack1.push(stack2.top()->right);
                if (stack2.top()->left != nullptr)
                    stack1.push(stack2.top()->left);
                vv2.push_back(stack2.top()->val);
                stack2.pop();
            }
            if(!vv2.empty())
                v.push_back(vv2);
        }
        return v;
    }
};