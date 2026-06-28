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

        if(root == NULL) {
            return NULL;
        }

        if(root == p || root == q) {
            return root;
        }

        //DFS on left subtree and right subtree.

        TreeNode* left = lowestCommonAncestor(root->left,p,q);
        TreeNode* right = lowestCommonAncestor(root->right,p,q);
        
        //Obtained information from both left and right subtree of root, That whether any p or q exists there.

        if((left == p && right == q) || (left == q && right == p))
        {
            //left and right subtree of this root are the childs p and q.So root is LCA.
            return root;
        }

        //Got Null from any one side.

        else if(!left)
        {
            //For this root.There is nothing on the left.But on it's right we get either or them.i.e the another one is below that founded.i.e founded is answer.
            return right;
        }

        return left;

        //TC : O(n)
        //SC : O(n)

    }
};