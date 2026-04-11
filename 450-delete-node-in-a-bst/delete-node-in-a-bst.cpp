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


        //We need the root node(Top node) of the final bst.
        //Search The node to be deleted.

        if(root == nullptr)
        {
            return NULL;//NULL.
        }

        else if(root->val < key)
        {
            root->right = deleteNode(root->right,key);
        }

        else if(root->val > key)
        {
            root->left = deleteNode(root->left,key);
        }

        else
        {
            //We got root == node to be deleted.

            //Lets see that node to be deleted == root has no child or , one child , or 2 childs.

            if(root->left == nullptr && root->right==nullptr)
            {
                delete root;
                root = nullptr;
            }

            else if(root->right == nullptr && root->left !=nullptr)
            {
                TreeNode* temp = root->left;//1100
                delete root;//1200
                root = nullptr; 
                return temp;//Will go to the right of node which comed ahead of the parent node after backtracking.
            }
            else if(root->right !=nullptr && root->left == nullptr)
            {
                TreeNode* temp = root->right;
                delete root;
                root = nullptr;
                return temp; 
            }
            else
            {
                TreeNode* parent = root;
                TreeNode* child  = root->left;//left subtree mei jao.Waha se rightmost find karo.

                while(child->right)
                {
                    parent  = child;
                    child = child->right;
                }

                if(parent == root)
                {
                    child->right = parent->right;   
                    delete parent;
                    parent = nullptr;
                    return child;
                }

                else
                {
                    parent->right = child->left;
                    child->right = root->right;
                    child->left = root->left;
                    delete root;
                    root = nullptr;
                    return child;
                }
            }

        }
        return root;
        //TC:O(Logn)
        //SC:O(Logn)
    }
};