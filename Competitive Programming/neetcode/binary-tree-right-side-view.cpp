/*
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
    void get_view(TreeNode* root,vector<int>& right_view,int &idx,int current_level){
        if(!root || (!root->right && !root->left) ){
            return;
        }
        if(current_level + 1 > idx){
            if(root->right){
                right_view.push_back(root->right->val);
            }
            else{
                right_view.push_back(root->left->val);
            }
            idx = idx+1;
        }
        get_view(root->right,right_view,idx,current_level+1);
        get_view(root->left,right_view,idx,current_level+1);
    }

    vector<int> rightSideView(TreeNode* root) {
        vector<int> right_view;
        if(!root) return right_view;
        int idx = 0;
        
        right_view.push_back(root->val);
        get_view(root,right_view,idx,0);

        return right_view;
    }
};
