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
    map<int, set<pair<int, int>>> m;
    
    void put(TreeNode *node, int x, int h) {
        if (node == NULL) return;
        // m[x].push_back(node->val);
        m[x].insert({h, node->val});
        put(node->left, x-1, h+1);
        put(node->right, x+1, h+1);
    }
    
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        put(root, 0, 0);
        vector<vector<int>> ans;
        for (auto it : m) {
            vector<int> temp;
            for (auto ii : it.second) {
                temp.push_back(ii.second);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};