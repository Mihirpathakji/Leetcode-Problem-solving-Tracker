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

    TreeNode* deleteHelper(TreeNode* root,unordered_set<int>& st,vector<TreeNode*> &result) {

       if(root == NULL) {
            return NULL;
       }    

       //Bottom - Up DFS.

       //First Go to the extreme left depth and extreme right depth. 

       root->left = deleteHelper(root->left,st,result);
       root->right = deleteHelper(root->right,st,result);

        //is this root node to be deleted ?

        if(st.find(root->val)!=st.end()) {
            //We have to delete this root.
            //Store it's left and right child if exists.

            if(root->left) {
                result.push_back(root->left);
            }

            if(root->right) {
                result.push_back(root->right);
            }

            //We had deleted this node.So,We return NULL To it's parent.

            return NULL;
        }

        return root;

    }

   
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {

        vector<TreeNode*>result;

        //We have to see whether this root is present in to_delete or not.
        //we can use a set .since in set .find() takes O(1).

        unordered_set<int>st;
        for(auto it : to_delete) {
            st.insert(it);
        }

        deleteHelper(root,st,result);   

        if(st.find(root->val) == st.end()) {
            result.push_back(root);
        }    

        return result;

        //TC : O(n)
        //SC : O(n)

    }
};