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

vector<int>answer(TreeNode* root,vector<int>&ans)
{   
    if(root == NULL)
    {
        return {};
    }

    //A+B == Left -> root -> right
    answer(root->left,ans);
    ans.push_back(root->val);

    answer(root->right,ans);

    return ans;

    //TC:O(N)
    //SC:O(N)

}
class Solution {
public:

    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>ans;
        return answer(root,ans);
       
    }
};