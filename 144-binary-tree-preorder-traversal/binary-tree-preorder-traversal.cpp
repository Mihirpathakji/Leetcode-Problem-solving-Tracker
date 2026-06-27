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
    vector<int> preorderTraversal(TreeNode* root) {

        vector<int>ans;//root->left->right

        while(root)
        {
            if(!root->left)
            {       
                ans.push_back(root->val);
                root = root->right;
            }
            else
            {
                //if it is not seen first.i.e There is No loop than only push it.Since we need to push only it's first occurance as root out of it's multiple traversals.

                TreeNode* temp = root->left;

                while(temp->right && temp->right!=root)
                {
                    temp = temp->right;
                }        

                if(temp->right == NULL)
                {
                    //i.e there is no loop.//It is first Occurance of that root.
                    ans.push_back(root->val);
                    //Now made the loop since it dosent exists.So that it's future occurance will not be pushed.

                    temp->right = root;
                    //We will do this for every root which is not having looped.root->left->right.

                    root = root->left;
                }

                else
                {
                    temp->right = NULL;
                    root = root->right; 
                }
            }
        }
            return ans;
        
        
            //TC : O(n)
            //SC : O(1)
    }
};