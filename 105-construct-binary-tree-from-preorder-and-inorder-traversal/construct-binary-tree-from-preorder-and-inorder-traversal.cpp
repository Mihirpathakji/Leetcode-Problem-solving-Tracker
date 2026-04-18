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

    int find(vector<int>&in,int target,int start,int end)
    {
        for(int i=start;i<=end;i++)
        {
            if(in[i] == target)
            {
                return i;
            }
        }
        return -1;
    }

    TreeNode* build_tree(vector<int>&pre,vector<int>&in,int instart,int inend,int index)
    {
        if(instart>inend)
        {
            return nullptr;
        }

        TreeNode* root = new TreeNode(pre[index]);
        int pos =  find(in,pre[index],instart,inend);//Find the root node of the Preorder array in the inorder array. 

        root->left = build_tree(pre,in,instart,pos-1,index+1);
        root->right = build_tree(pre,in,pos+1,inend,index+(pos-instart+1));
        return root;
   
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int index = 0;
        return build_tree(preorder,inorder,0,inorder.size()-1,index);
    }

};