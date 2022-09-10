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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<TreeNode*>> w;
        vector<vector<int>> ans;
        if(root==NULL)
            return {};
        w.push_back({root});
        int i=0;
        while(1){
            vector<TreeNode*> l;
            for(TreeNode* x: w[i]){
                if(x->left!=NULL) l.push_back(x->left);
                if(x->right!=NULL) l.push_back(x->right);
            }
            if(l.empty()) break;
            w.push_back(l);
            i++;
        }
        for(vector<TreeNode*> x: w){
            vector<int> z;
            for(TreeNode* y: x)
                z.push_back(y->val);
            ans.push_back(z);
        }
        return ans;
    }
};