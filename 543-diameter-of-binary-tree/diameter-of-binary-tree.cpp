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

    int solve(TreeNode* root, int& max_len)
    {

        if(root == NULL)
        {
            return 0;//no left_edges / right_edges
        }

        int left_edges = solve(root->left,max_len);//
        int right_edges = solve(root->right,max_len);//

        max_len = max(max_len,left_edges + right_edges);

        return max(left_edges,right_edges) + 1;

    }

    int diameterOfBinaryTree(TreeNode* root) {

        int max_len = INT_MIN;

        solve(root,max_len);

        return max_len;

        //TC : O(n)
        //SC : O(n)
    }
};