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

    void mydfssum(TreeNode* root,int& sum,int& final_sum) {

        if(root == NULL) {
            return;
        }

        sum = (sum*10 + root->val);

        if(root->left == NULL && root->right == NULL) {
            final_sum += sum;
        }

        mydfssum(root->left,sum,final_sum);
        mydfssum(root->right,sum,final_sum);

        sum/=10;
    }

    int sumNumbers(TreeNode* root) {

        int sum = 0;
        int final_sum = 0;
        mydfssum(root,sum,final_sum);

        return final_sum;

        //TC : O(n)
        //SC : O(n)

        //sum at any node is : curr_sum*10 + itself value.

    }
};