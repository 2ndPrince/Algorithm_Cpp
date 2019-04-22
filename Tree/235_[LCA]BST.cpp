// 235. Lowest Common Ancestor of a Binary Search Tree
// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/

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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        int rr = root->val;
        int pp = p->val;
        int qq = q->val;
        if(rr > max(pp,qq)) return lowestCommonAncestor(root->left, p, q);
        if(rr < min(pp,qq)) return lowestCommonAncestor(root->right, p, q);
        return root;
    }
};
