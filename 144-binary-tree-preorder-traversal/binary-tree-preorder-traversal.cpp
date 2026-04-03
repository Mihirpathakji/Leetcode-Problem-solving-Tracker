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

    vector<int>answer(TreeNode* root,vector<int>&ans)
    {
        if(root == NULL)
        {
            return {};
        }

        //Pre Order Traversal:
        ans.push_back(root->val);//Pre -> Operator .(Root) //1 2 3 
        answer(root->left,ans);//A -> Left
        answer(root->right,ans);//B -> right

        return ans;//1 2 3 

        //TC:O(n)
        //SC:O(n)

    }
   
    vector<int> preorderTraversal(TreeNode* root) {

        vector<int>ans;
        return answer(root,ans);

    }

};