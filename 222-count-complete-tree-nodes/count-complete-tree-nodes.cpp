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
    int countNodes(TreeNode* root) {

        //Recursive Approach:

       // ->Count total nodes from Left subtree of 1 
       // ->Count total nodes from right subtree of 1 
       // -> ans = nodes of leftsubtree + nodes of rightsubtree + 1.

       if(root == NULL)
       {
            return 0;
       }

        int nodes_from_left_subtree = countNodes(root->left);//1->l ==3    1 //A
        
        //200  2->left     -> 1    
        //400  4->left == 0
        //600  

        int nodes_from_right_subtree = countNodes(root->right);// 2 //B
        //400 -> right  = NULL
        //0 
        //500 
        //300

        return nodes_from_left_subtree + nodes_from_right_subtree + 1;//3  1  2//+ ->root node
        //3 + 2 + 1 == 6


        //PostOrder Traversal.
        
        //TC:O(N)

        //SC:O(N)AUXILLIARY
              

    }
};