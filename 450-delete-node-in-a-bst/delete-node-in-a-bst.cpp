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

    TreeNode* deleteNode(TreeNode* root, int key) {

        if(root == NULL)
        {
            return nullptr;
        }

        if(root->val < key)
        {
            root->right =  deleteNode(root->right,key);
        }

        else if(root->val > key)
        {
            root->left = deleteNode(root->left,key);
        }

        else
        {
            TreeNode* ans = root;//We got the Node to be deleted.
            TreeNode* temp = ans;

            //Case 1 : No  child :-   

            if(ans->left==NULL && ans->right==NULL)
            {
                delete ans;
                ans = nullptr;
                return nullptr;
            }

            //Case 2: Single Child :

            else if(ans->left!=NULL && ans->right==NULL)
            {   
                TreeNode* temp  = ans->left;
                delete ans;
                ans = nullptr;
    
                return temp;
            }

            else if(ans->left==NULL && ans->right!=NULL)
            {   
                TreeNode* temp = ans->right;
                delete ans;
                ans = nullptr;
                return temp;
            }

            //Case 3 :

            //Node to be Deleted has two childs :

            TreeNode* parent  = root;
            TreeNode* child  = parent->left;


            //Went to the LEFT subtree and Find it's rightmost.

            while(child->right)
            {   
                parent = child;
                child = child->right;
            }   

            
            if(parent == root)
            {   
                child->right = root->right;
                delete root;
                return child;
            }   

            else
            {
                parent->right = child->left;
                child->left = root->left;
                child->right = root->right;
                delete root;
                return child; 
            }
        }

        return root;

    }
};