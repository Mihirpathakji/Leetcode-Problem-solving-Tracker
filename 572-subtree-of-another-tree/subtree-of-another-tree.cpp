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

bool isIdentical(TreeNode* p,TreeNode* q)
{

    if(p == NULL || q == NULL)
    {
        return p == q;
    }

    return (p->val == q->val) && isIdentical(p->left,q->left) && isIdentical(p->right,q->right);
 
}
             

class Solution {
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {

        //Iterative -> NOT GOOD. Recursively.

        if(root == NULL || subRoot == NULL)
        {
            return root == subRoot;
        }

        if(root->val == subRoot->val && isIdentical(root,subRoot))
        {
            return true;
        }

        //Not got the identical tree at the root node of the both .Hence checked at the Left and at the right.

        return isSubtree(root->left,subRoot) || isSubtree(root->right,subRoot);

        //Either we had got the identical subRoot in the left part of the currrent Node or in the right part of the current node.

    }
};