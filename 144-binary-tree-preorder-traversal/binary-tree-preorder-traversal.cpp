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

        vector<int>ans;
            
        while(root)
        {
            if(root->left)
            {
                //Check that this left subtree is traversed or not.
                //1.Loop is there means the left subtree is entirely traversed.Hence left->root->right.Now it's time for the root and it's right.
                
                TreeNode* temp = root->left;
                
                while(temp->right && temp->right != root)
                {
                    temp = temp->right;
                }
                
                if(temp->right == NULL)
                {
                    //There is no linkage and that temp is also not printed.Lets first create a linkage for all such nodes.
                    
                    ans.push_back(root->val);
                    temp ->right= root;
                    
                    //Form linkage for all such nodes on the left.Since in inorder traversal we do all possible lefts first.
                    root = root->left;                
                } 
                else
                {
                    //loops is already there.i.e the left part is already printed and traversed.Now after the left it's time for the root and right.
                    temp->right = NULL;
                    root = root->right;
                }
            }
            
            else
            {
                //left is not there , Now remains the root and it's right. 
                ans.push_back(root->val);
                root = root->right;
            }
            
        }
        
        //TC : O(n*2) = O(n)
        //SC : O(1)
        
        return ans;
        
    }
};