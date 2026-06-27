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

    TreeNode* Create_Tree(vector<int>&Preorder,vector<int>&Inorder,int Preindex,int left,int right,unordered_map<int,int> &mp)
    {   
        if(left > right)
        {
            return nullptr;
        }

        //Create the root Node:

        TreeNode* root = new TreeNode(Preorder[Preindex]);//Pass Preindex by the value -> Wrong ans. Since it is used in -> Pass it by reference.

        //Search this Preorder[Preindex]  in the Inorder Array in the range [left,right] : and find it's index

        int pos = mp[Preorder[Preindex]];

        //Build left subtree for that root:

        root->left =  Create_Tree(Preorder,Inorder,Preindex+1,left,pos - 1,mp);

        //Build right subtree for that root:

        root->right = Create_Tree(Preorder,Inorder,Preindex +(pos - left)+1,pos + 1,right,mp);

        return root;

    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
      
        int index1 = 0;
        
        unordered_map<int,int>mp;
        for(int i = 0;i < inorder.size();i++)
        {
            mp[inorder[i]] = i;
        }

        return Create_Tree(preorder,inorder,index1,0,inorder.size()-1,mp);
        
    }
};