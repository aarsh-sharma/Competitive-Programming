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
    vector<int> maxms = {0};
    int diameter(TreeNode *root) {
        if (root == NULL) return 0;
        int ll = diameter(root->left);
        int rr = diameter(root->right);
        maxms.push_back(ll+rr);
        return (1 + max(ll, rr));
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        diameter(root);
        return *max_element(maxms.begin(), maxms.end());
    }
};