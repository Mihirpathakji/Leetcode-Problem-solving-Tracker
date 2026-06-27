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

    TreeNode* Tree(vector<int> &inorder,vector<int> &postorder,int instart,int inend,int postindex,unordered_map<int,int> &mp)
    {   
        if(instart > inend)
        {
            return NULL;
        }

        //1.Create a node with value of the postorder[postindex].

        TreeNode* root = new TreeNode(postorder[postindex]);

        //2.We didnt know the direction either left or right where to insert this node.Hence ,find the index of the postorder[postindex] value in the inorder.

        int pos = mp[postorder[postindex]];// O(n)

        //3.Build left subtree and the rightsubtree.

        root->left = Tree(inorder,postorder,instart,pos-1,(postindex-(inend-pos))-1,mp);

        root->right = Tree(inorder,postorder,pos+1,inend,postindex-1,mp);

        return root;

    }//O(n).


    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {

        
        //Find -> O(n) to find index of every element of postorder in inorder.We can precompute that and store the index of element of postorder in inorder.

        //We need index of element in inorder.Since every of postorder also occurs in inorder.We can hash inorder values with it's indices.

        unordered_map<int,int>mp;//value,index in inorder.

        for(int i = 0; i < inorder.size(); i++)
        {
            mp[inorder[i]] = i;
        }

        return Tree(inorder,postorder,0,inorder.size()-1,postorder.size()-1,mp);//root element in the postorder will be at postorder.size()-1.     

        //TC : O(n)
        //SC : O(n)

    }
};