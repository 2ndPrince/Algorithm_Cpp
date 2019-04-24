// https://leetcode.com/problems/smallest-string-starting-from-leaf/

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
    string smallestFromLeaf(TreeNode* root) {
        if(root == NULL) return "";
        if(root->left == NULL && root->right == NULL) return string(1, root->val + 'a');
        
        string l = smallestFromLeaf(root->left);
        string r = smallestFromLeaf(root->right);
        l.push_back(root->val + 'a');
        r.push_back(root->val + 'a');
        if(root->left == NULL) return r;
        if(root->right == NULL) return l;
        return min(l, r);
    }
};
