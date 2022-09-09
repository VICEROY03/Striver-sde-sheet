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
    vector<int> inorderTraversal(TreeNode* root) {
        int i=-1;
        stack<TreeNode*> s;
        vector<int> ans;
        TreeNode* tmp = root;
        if(tmp!=NULL)
            s.push(tmp);
        else
            return {};
        tmp = tmp->left;
        while(!s.empty() || tmp!=NULL){
            if(tmp==NULL){
                tmp = s.top();
                ans.push_back(tmp->val);
                s.pop();
                tmp = tmp->right;
            }
            else{
                s.push(tmp);
                tmp = tmp->left;
            }
        }
        return ans;
    }
};