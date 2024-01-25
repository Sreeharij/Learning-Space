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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> zigzag_order;
        if(!root) return zigzag_order;
        queue<TreeNode*> q;
        q.push(root);
        int current = 1,next =0;
        TreeNode* ptr;
        int required_idx=0;
        vector<int> temp(current);
        bool flag = true;
        while(!q.empty()){
            if(current == 0){
                current = next;
                next = 0;

                if(flag){
                    flag = false;
                    required_idx = current - 1;
                }
                else{
                    flag = true;
                    required_idx = 0;
                }
                
                zigzag_order.push_back(temp);
                temp.clear();
                temp.resize(current);
            }

            ptr= q.front();
            q.pop();
            current -= 1;
            if(flag){
                temp[required_idx++] = ptr->val;
            }
            else{
                temp[required_idx--] = ptr->val;
            }

            if(ptr->left){
                q.push(ptr->left);
                next += 1;
            }
            if(ptr->right){
                q.push(ptr->right);
                next += 1;
            }
        }

        zigzag_order.push_back(temp);
        return zigzag_order;
    }
};
