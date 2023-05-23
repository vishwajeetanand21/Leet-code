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
    void solve(TreeNode* root,vector<vector<int>> &ans){
        if(root==NULL) return ;
        
        stack<TreeNode*> curr;
        stack<TreeNode*> next;
        
        bool leftToRight=true;
        
		//push  root to the curr
        curr.push(root);
         vector<int> v;
        while(!curr.empty()){
            TreeNode* node=curr.top();
            curr.pop();
            if(node){
                v.push_back(node->val);
				
				//add data in the next according to the order (leftToRight)
                if(leftToRight){
                    if(node->left){
                        next.push(node->left);
                    }
                    if(node->right){
                        next.push(node->right);
                    }
                }
                else{
                    if(node->right){
                        next.push(node->right);
                    }
                    if(node->left){
                        next.push(node->left);
                    }
                }
            }
            
            if(curr.empty()){
                ans.push_back(v);
                leftToRight=!leftToRight;
                swap(curr,next);
                v.clear();
            }
        }
    }
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        solve(root,ans);
        return ans;
    }
};