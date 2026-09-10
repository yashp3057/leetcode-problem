class Solution {
public:
    int ans = 0;

    void solve(TreeNode* root) {
        if (root == nullptr)
            return;

        int sum = 0;
        int count = 0;

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* y = q.front();
            q.pop();

            sum += y->val;
            count++;

            if (y->left != nullptr)
                q.push(y->left);

            if (y->right != nullptr)
                q.push(y->right);
        }

        if (sum / count == root->val)
            ans++;

        solve(root->left);
        solve(root->right);
    }

    int averageOfSubtree(TreeNode* root) {
        solve(root);
        return ans;
    }
};