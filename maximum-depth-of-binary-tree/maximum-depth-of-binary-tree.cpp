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
    int maxDepth(TreeNode* root) {
        // Write our code here
    
    //base case->if the root will contain NULL, we will return NULL
    if(root==NULL)
    {
        return 0;
    }
    //this means that, there is some data present in our tree
    int ans=1;//so we will initialize ans with 1
    ans=ans+max(maxDepth(root->left),maxDepth(root->right));
    //ans=ans(our pervious answer)+maximum amount of height in left and right recursion  
    return ans;
    }
};