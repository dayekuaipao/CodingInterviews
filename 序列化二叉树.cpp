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
    void SerializeCore(TreeNode* root, stringstream& ss)
    {
        if (root == nullptr)
        {
            ss << '#' << '!';
            return;
        }
        else
        {
            ss << root->val << '!';
        }
        SerializeCore(root->left, ss);
        SerializeCore(root->right, ss);
    }
    char* Serialize(TreeNode* root)
    {
        stringstream ss;
        SerializeCore(root, ss);
        string* str = new string(std::move(ss.str()));
        return const_cast<char*>(str->c_str());
    }
    TreeNode* DeserializeCore(stringstream& ss)
    {
        string str;
        getline(ss, str, '!');
        if (str != "#")
        {
            int val = atoi(str.c_str());
            TreeNode* node = new TreeNode(val);
            node->left = DeserializeCore(ss);
            node->right = DeserializeCore(ss);
            return node;
        }
        else
        {
            return nullptr;
        }
    }
    TreeNode* Deserialize(char* str)
    {
        stringstream ss;
        ss << str;
        return DeserializeCore(ss);
    }
};