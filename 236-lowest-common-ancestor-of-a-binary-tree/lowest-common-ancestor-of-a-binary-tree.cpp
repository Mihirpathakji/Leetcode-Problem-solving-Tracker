/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:


    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

        //Depth first search.
        
        if(root == NULL)  {
            return NULL;
        }

        if(root == p || root == q) {
            return root;
        }

        //Check if p or q exists in the left subtree.

        TreeNode* left = lowestCommonAncestor(root->left,p,q);
        TreeNode* right = lowestCommonAncestor(root->right,p,q);

        if(left != NULL && right != NULL) {
            return root;
        }

        if(left != NULL) {
            return left;
        }

        return right;

        //TC : O(n)
        //SC : O(n)

    }
};