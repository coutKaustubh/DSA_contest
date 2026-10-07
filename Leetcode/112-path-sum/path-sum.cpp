class Solution {
public:
    bool dfs(TreeNode* root, int targetSum) {
        if (root == nullptr) return false;
        targetSum -= root->val;
        if (root->left == nullptr && root->right == nullptr)return targetSum == 0;
        return dfs(root->left, targetSum) ||dfs(root->right, targetSum);
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        return dfs(root, targetSum);
    }
};