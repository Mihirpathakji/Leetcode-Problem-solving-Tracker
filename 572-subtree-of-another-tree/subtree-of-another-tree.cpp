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

    bool isIdentical(TreeNode* p,TreeNode* q)
    {
        if(p == NULL || q == NULL)
        {
            return p == q;
        }

        return (p->val == q->val) && isIdentical(p->left,q->left) && isIdentical(p->right,q->right);
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {

        //Find the top of the subRoot in the Main Tree
        //Moment you found the same top node. Check whether both of those subtrees are identical/

        //Edge Case :

        if(root == NULL || subRoot == NULL)
        {
            return root == subRoot;
        }

        if( (root->val == subRoot->val) && isIdentical(root,subRoot))
        {
            return true;//isIdentical -> TC : O(M).M - Number of nodes in the subroot.
        }
        
        return isSubtree(root->left,subRoot) || isSubtree(root->right,subRoot);

        //TC:O(N*M) N -> Number of nodes in Main Tree. M - Number of nodes in the subRoot.For each root in the Main Tree in worst case we will be checking that whole subRoot is identical with that node or not.

        //SC: O(N) =M 

    }
};