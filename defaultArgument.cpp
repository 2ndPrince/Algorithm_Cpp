// 1026. Maximum Difference Between Node and Ancestor
// https://leetcode.com/problems/maximum-difference-between-node-and-ancestor/
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
    int max_difference = 0;
    void dfs(TreeNode* branch, int min_value=INT_MAX, int max_value=INT_MIN){ // using default arguments.
        if(!branch) return;
        if(min_value!=INT_MAX){
            max_difference = max(max_difference, branch->val-min_value);
            max_difference = max(max_difference, max_value-branch->val);
        }
        min_value = min(min_value, branch->val);
        max_value = max(max_value, branch->val);
            
        dfs(branch->left, min_value, max_value);
        dfs(branch->right, min_value, max_value);
    }
    int maxAncestorDiff(TreeNode* root) {
        dfs(root);
        return max_difference;
    }
};
