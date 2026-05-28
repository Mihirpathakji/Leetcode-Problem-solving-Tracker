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
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {

        //Storing the final answer in root1.

        //Case1 : 
        if(!root1 && !root2)
        {
            return NULL;
        }
        else if(!root1 && root2)
        {
            return root2;
        }
        else if(root1 && (!root2))
        {
            return root1;
        }
        else
        {
            root1->val = root1->val + root2->val;
        }

        //Attaching the left merged subtrees to the left parent.

        root1->left = mergeTrees(root1->left,root2->left);

        //Attaching the right merged subtrees to the right parent.

        root1->right = mergeTrees(root1->right,root2->right);
        
        return root1;
        
    }
};