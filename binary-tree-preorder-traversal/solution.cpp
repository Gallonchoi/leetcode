class Solution {
public:

    Solution() {}

    vector<int> preorderTraversal(TreeNode* root) {
        std::vector<int> list;
        std::stack<TreeNode*> nodeStack;

        while(1) {
            if(root) {
                list.push_back(root->val);
                nodeStack.push(root);
                root = root->left;
            } else if(nodeStack.empty()) {
                break;
            } else {
                root = nodeStack.top();
                root = root->right;
                nodeStack.pop();
            }
        }
        return list;
    }
};
