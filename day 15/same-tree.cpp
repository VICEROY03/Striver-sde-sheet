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
    void dfs(TreeNode* p, TreeNode* q, bool& f){
        if(p==NULL && q==NULL)
            return;
        if(p==NULL || q==NULL){
            f=0;
            return;
        }
        if(p->val!=q->val){
            f=0;
            return;
        }
        dfs(p->left, q->left, f);
        dfs(p->right, q->right, f);
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        bool f=1;
        dfs(p, q, f);
        return f;
    }
};