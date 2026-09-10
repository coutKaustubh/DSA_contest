class Solution {
public:
    int ans = 0;

    pair<int, int> solve(TreeNode* root) {
        if (root == NULL)
            return {0, 0};

        pair<int, int> left = solve(root->left);
        pair<int, int> right = solve(root->right);

        int count = left.first + right.first + 1;
        int sum = left.second + right.second + root->val;

        if (sum / count == root->val)
            ans++;

        return {count, sum};
    }

    int averageOfSubtree(TreeNode* root) {
        solve(root);
        return ans;
    }
};