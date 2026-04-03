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

        //Recursively:

        if(root == NULL)
        {
            return 0;
        }

        //Calculate the Height of Left subtree from the root node 

        int left_Subtree_Height = maxDepth(root->left);//1   0  // A->LEFT
        
        //Calculate the height of the right subtree from root node.

        int right_Subtree_Height = maxDepth(root->right);// 0   2 //  B->RIGHT

        //Total Height after including the root Node.

        return max(left_Subtree_Height,right_Subtree_Height)+1;//1  1   2 // Root 
        

        //Postorder Traversal
        //TC:O(N)
        //SC:O(N)->AUXILLIARY SPACE.
    }
};