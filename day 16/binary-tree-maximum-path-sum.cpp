class Solution {
public:
    int helper(TreeNode* tmp, int& maxg){
        if(tmp==NULL) return 0;
        int l=helper(tmp->left, maxg), r=helper(tmp->right, maxg);
        maxg = max(max(max(max(tmp->val, tmp->val+l), tmp->val+r), tmp->val+r+l), maxg);
        return max(max(l+tmp->val, r+tmp->val), tmp->val);
    }
    
    int maxPathSum(TreeNode* root) {
        int maxg = INT_MIN;
        helper(root, maxg);
        return maxg;
    }
};