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

    int find(vector<int> &inorder,int instart,int inend,int target)
    {
        for(int i = instart; i <= inend;i++)
        {
            if(inorder[i] == target)
            {   
                return i;
            }
        }

        return -1;
    }

    TreeNode* Tree(vector<int> &inorder,vector<int> &postorder,int instart,int inend,int postindex)
    {   
        if(instart > inend)
        {
            return NULL;
        }

        //1.Create a node with value of the postorder[postindex].

        TreeNode* root = new TreeNode(postorder[postindex]);

        //2.We didnt know the direction either left or right where to insert this node.Hence ,find the index of the postorder[postindex] value in the inorder.

        int pos = find(inorder,instart,inend,postorder[postindex]);

        //3.Build left subtree and the rightsubtree.

        root->left = Tree(inorder,postorder,instart,pos-1,postindex-(inend-pos)-1);

        root->right = Tree(inorder,postorder,pos+1,inend,postindex-1);

        return root;

    }


    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {

        return Tree(inorder,postorder,0,inorder.size()-1,postorder.size()-1);
        
    }
};