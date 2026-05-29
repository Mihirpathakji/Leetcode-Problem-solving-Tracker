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

    int get_my_ans(TreeNode* root)
    {

        if(root == NULL)
        {
            return 0;//empty subtree has 0 nodes in it.
        }

        int nodes_on_left = get_my_ans(root->left);//Obtain total nodes from the left subtree.
        int nodes_on_right = get_my_ans(root->right);//Obtain total nodes form the right subtree.

        return nodes_on_left + nodes_on_right + 1;

    }

    int countNodes(TreeNode* root) {

        int size = 0;
        size = get_my_ans(root); 
        
        return size;
        
    }
};