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
    vector<int> preorderTraversal(TreeNode* root) {
        stack<TreeNode*> s;
        vector<int> ans;
        TreeNode* tmp = root;
        if(tmp!=NULL){
            ans.push_back(tmp->val);
            s.push(tmp);
            tmp = tmp->left;
        }
        else
            return {};
        
        while(!s.empty() || tmp!=NULL){
            if(tmp==NULL){
                tmp = s.top();
                s.pop();
                tmp = tmp->right;
            }
            else{
                ans.push_back(tmp->val);
                s.push(tmp);
                tmp = tmp->left;
            }
        }
        return ans;
    }
};