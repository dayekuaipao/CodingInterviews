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
    vector<vector<int> > FindPath(TreeNode* root, int expectNumber) 
    {
        vector<vector<int> > paths;
        vector<int> path;
        if (root != nullptr)
        {
            FindPathCore(root, paths, path, expectNumber);
        }
        return paths;
    }
    void FindPathCore(TreeNode* node, vector<vector<int> >& paths, vector<int>& path, int expectNumber)
    {
        path.push_back(node->val);
        if (node->left == nullptr && node->right == nullptr)
        {
            int count = 0;
            for (int i = 0; i < path.size(); ++i)
            {
                count += path[i];
            }
            if (count == expectNumber)
            {
                paths.push_back(path);
            }
        }
        if(node->left != nullptr)
        {
            FindPathCore(node->left, paths, path, expectNumber);
        }
        if (node->right != nullptr)
        {
            FindPathCore(node->right, paths, path, expectNumber);
        }
        path.pop_back();
    }
};