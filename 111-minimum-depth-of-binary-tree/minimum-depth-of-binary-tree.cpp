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

    int solve(TreeNode* root,int& min_Depth)
    {
        if(root == NULL)
        {
            return 0;
        }

        int left = solve(root->left,min_Depth);//1  0
        
  
        int right = solve(root->right,min_Depth);//2 

        if(root->right == NULL)
        {
            return 1 + left;
        }
        
        if(root->left == NULL)
        {
            return 1 + right;
        }

        min_Depth = min(left,right) + 1;

        return min_Depth;//2
    }

    int minDepth(TreeNode* root) {
        
        int min_Depth = INT_MAX;
        int ans = solve(root,min_Depth);
        return ans;
        
    }


};