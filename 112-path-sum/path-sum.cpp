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

    void mydfscheck(TreeNode* root,int targetSum,int& sum, bool& flag) {

        if(root == NULL) {
            return;
        }

        sum += root->val;

        if(root->left == NULL && root->right == NULL && sum == targetSum) {
            flag = true;
            return;
        }

        mydfscheck(root->left,targetSum,sum,flag);
        mydfscheck(root->right,targetSum,sum,flag);

        //we had done checking this path.

        sum -= root->val;

    }

    bool hasPathSum(TreeNode* root, int targetSum) {

        int sum = 0;
        bool flag = false;
        mydfscheck(root,targetSum,sum,flag);

        return flag;

    }
};