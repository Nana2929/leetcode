/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int max_diff = 0;
    int maxAncestorDiff(TreeNode* root) {
        helper(root);
        return max_diff;
    }
    pair<int, int> helper(TreeNode* n){
        if(n == nullptr){
            return make_pair(-INT_MAX, INT_MAX);
        }
        if (n->left == n-> right && n->right==nullptr){
            return make_pair(n->val, n->val);
        }
        pair<int, int> left = helper(n->left);
        pair<int, int> right = helper(n->right);
        int max = left.first > right.first ? left.first : right.first;
        int min = left.second < right.second ? left.second : right.second;
        max_diff = max_diff > abs(n->val - max) ? max_diff : abs(n->val - max);
        max_diff = max_diff > abs(n->val - min) ? max_diff : abs(n->val - min);
        max = max > n->val ? max : n->val;
        min = min < n->val ? min : n->val;
        return make_pair(max, min);
    }
};