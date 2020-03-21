/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool check(TreeNode *l, TreeNode *r) {
        if (l == NULL and r == NULL) return true;
        if (r == NULL and l != NULL) return false;
        if (r != NULL and l == NULL) return false;
        if (l->val != r->val) return false;
        if (!check(l->left, r->right)) return false;
        if (!check(l->right, r->left)) return false;
        return true;
    }
    
    bool isSymmetric(TreeNode* root) {
        if (root == NULL) return true;
        return check(root->left, root->right);
    }
};