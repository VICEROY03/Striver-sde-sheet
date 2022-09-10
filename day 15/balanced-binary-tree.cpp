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
    int help(TreeNode* tmp, bool& f){
        if(tmp==NULL)
            return 0;
        int l=help(tmp->left, f), r=help(tmp->right, f);
        if(abs(l-r)>1) f=0;
        return 1+max(l,r);
    }
    bool isBalanced(TreeNode* root) {
        bool f=1;
        help(root, f);
        return f;
    }
};