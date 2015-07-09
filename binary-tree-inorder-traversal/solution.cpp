class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        std::vector<int> list;
        std::stack<TreeNode*> nodeStack;

        while(1) {
            if(root) {
                nodeStack.push(root);
                root = root->left;
            } else if(nodeStack.empty()) {
                break;
            } else {
                root = nodeStack.top();
                list.push_back(root->val);
                root = root->right;
                nodeStack.pop();
            }
        }
        return list;
    }
};
