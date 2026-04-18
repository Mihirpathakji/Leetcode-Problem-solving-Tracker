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

    int search(vector<int>&Inorder,int target,int left,int right)
    {
        for(int i = 0;i<Inorder.size();i++)
        {
            if(Inorder[i] == target)
            {
                return i;
            }
        }
        return -1;
    }

    TreeNode* Create_Tree(vector<int>&Preorder,vector<int>&Inorder,int& Preindex,int left,int right)
    {   
        if(left > right)
        {
            return nullptr;
        }

        //Create the root Node:

        TreeNode* root = new TreeNode(Preorder[Preindex]);//Pass Preindex by the value -> Wrong ans. Since it is used in -> Pass it by reference.

        //Search this Preorder[Preindex]  in the Inorder Array in the range [left,right] : and find it's index

        int index = search(Inorder,Preorder[Preindex],left,right);

        Preindex++;

        //Build left subtree for that root:


        root->left =  Create_Tree(Preorder,Inorder,Preindex,left,index-1);


        //Build right subtree for that root:

        root->right = Create_Tree(Preorder,Inorder,Preindex,index+1,right);

        return root;

    }


    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
      
        int index1 = 0;
        return Create_Tree(preorder,inorder,index1,0,inorder.size()-1);
        
    }
};