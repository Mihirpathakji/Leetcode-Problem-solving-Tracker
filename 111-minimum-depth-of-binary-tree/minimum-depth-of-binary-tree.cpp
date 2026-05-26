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

    void rec(TreeNode* root,int& level,int cl)
    {
        if(!root)
        {
            return;
        }

        if(!(root->left) && (!root->right))
        {
            //leaf node founded.
            level = min (level,cl);
        }

        rec(root->left,level,cl+1);
        rec(root->right,level,cl+1);       

    }

    int minDepth(TreeNode* root) {

        if(root == NULL)
        {
            return 0;
        }

        int level = INT_MAX;
        int cl = 1;//Current_level.
        rec(root,level,cl);
        return level;
        

        //TC: O(n)
        //SC : O(n)
    }
};