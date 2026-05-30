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

    bool is_Identical(TreeNode* root1,TreeNode* root2)
    {
        if(!root1 && !root2)
        {
            return true;
        }

        else if(root1 && !root2)
        {   
            return false;
        }
        else if(!root1 && root2)
        {
            return false;
        }
        else
        {
            if(root1->val == root2->val)
            {
                bool left_check = is_Identical(root1->left,root2->right);
                bool right_check = is_Identical(root1->right,root2->left);
                return left_check && right_check; 
            }
        }

        return false;
        
        }

    bool isSymmetric(TreeNode* root) {

        return is_Identical(root->left,root->right);
    }

};