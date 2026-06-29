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

    bool isOnePresent(TreeNode* root) {

        if(root == NULL) {
            return false;
        }

        if(root->val == 1) {
            return true;
        }

        //check if anywhere either from the left subtree of the child or from the right subtree of the child there is 1.

        return isOnePresent(root->left) || isOnePresent(root->right);

    }
   
    TreeNode* pruneTree(TreeNode* root) {

        if(root == NULL) {
            return NULL;
        }

        if(!isOnePresent(root->left)) {
            root->left = NULL;
        }

        if(!isOnePresent(root->right)) {
            root->right = NULL;  
        }

        pruneTree(root->left);
        pruneTree(root->right);

        if(root->left == NULL && root->right == NULL && root->val ==0) {
            return NULL;
        }          

        return root;
        
    }
};