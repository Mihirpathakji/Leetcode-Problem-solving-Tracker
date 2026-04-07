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

    TreeNode* insert(TreeNode* node,int target)
    {//400
        if(node == NULL)
        {
            return new TreeNode(target); //500
        }

        if(target <= node->val)
        {
            //insert at the left 
            node->left = insert(node->left,target);
        }
        else
        {
            node->right = insert(node->right,target);
            //400->right  = insert(700,5).
            //700->left = 500
        }

        return node;

    }

    TreeNode* insertIntoBST(TreeNode* root, int val) {

       TreeNode* ans =  insert(root,val);// (400,5)
       return ans;

       //TC: O(Logn)
       //SC: O(logn)    

    }
};