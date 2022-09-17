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
    bool isSymmetric(TreeNode* root) {
        vector<TreeNode*> u1,u2;
        if(root->left==NULL && root->right==NULL)
            return 1;
        if(root->left==NULL || root->right==NULL)
            return 0;
        u1.push_back(root->left);
        u2.push_back(root->right);
        while(!u1.empty() || !u2.empty()){
            int m=u1.size(),n=u2.size();
            vector<TreeNode*> v1,v2;
            if(m!=n)
                return 0;
            
            for(int i=0; i<n; i++){
                bool f1=1,f2=1;
                if(u1[i]->val!=u2[n-1-i]->val)
                    return 0;
                if(u1[i]->left==NULL && u2[n-1-i]->right==NULL)
                    f1=0;
                else if(u1[i]->left==NULL || u2[n-1-i]->right==NULL)
                    return 0;
                if(u1[i]->right==NULL && u2[n-1-i]->left==NULL)
                    f2=0;
                else if(u1[i]->right==NULL || u2[n-1-i]->left==NULL)
                    return 0;
                if(f1)
                    v1.push_back(u1[i]->left);
                if(f2)
                    v1.push_back(u1[i]->right);
            }
            for(int i=0; i<n; i++){
                bool f1=1,f2=1;
                if(u2[i]->val!=u1[n-1-i]->val)
                    return 0;
                if(u2[i]->left==NULL && u1[n-1-i]->right==NULL)
                    f1=0;
                else if(u2[i]->left==NULL || u1[n-1-i]->right==NULL)
                    return 0;
                if(u2[i]->right==NULL && u1[n-1-i]->left==NULL)
                    f2=0;
                else if(u2[i]->right==NULL || u1[n-1-i]->left==NULL)
                    return 0;
                if(f1)
                    v2.push_back(u2[i]->left);
                if(f2)
                    v2.push_back(u2[i]->right);
            }
            u1=v1;u2=v2;
        }
        return 1;
    }
};