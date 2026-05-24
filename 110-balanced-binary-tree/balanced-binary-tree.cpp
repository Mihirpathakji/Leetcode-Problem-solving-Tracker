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

    int Height(TreeNode* root)
    {   
        if(root == NULL)
        {
            return 0;
        }

        int leftHeight = Height(root->left);
        int rightHeight = Height(root->right);

        return max(leftHeight,rightHeight) + 1;

    }
    
    bool isBalanced(TreeNode* root) {

        //Check for the root:

        //|hl-hr| <= 1.
        if(root == NULL)
        {
            //empty tree is Always Balanced.
            return true;
        }

        int leftHeight = Height(root->left);
        int rightHeight = Height(root->right);

        if(abs(leftHeight - rightHeight) > 1)
        {
            //you need to check for the all the nodes on the left of root and on the right of the root.That whether they are balanced or not.You cannot return true.

            //But if root is not balanced you can directly return false;

            return false;
        }


        //root is balanced .Check Recursively whether all the nodes of the Left subtree and all nodes of the right substree are also balanced or not.

        return isBalanced(root->left) && isBalanced(root->right);

        //TC : O(n^2)
        //SC : O(n)
    }
};