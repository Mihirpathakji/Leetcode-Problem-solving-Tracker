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

    TreeNode* deleteHelper(TreeNode* root,unordered_set<int> &st,vector<TreeNode*> &result) {

        if(root == NULL) {
            return NULL;
        }

        //Bottom - Up : Went to the Maximum depth as possible.Than backtrack.And pop elements while backtracking.

        root->left = deleteHelper(root->left,st,result);
        root->right = deleteHelper(root->right,st,result);

        if(st.find(root->val)!=st.end()) {

            //Before deleting it, store it's left and right child if exists.

            if(root->left) {
                result.push_back(root->left);
            }

            if(root->right) {
                result.push_back(root->right);
            }

            //Now we can delete it.

            return NULL;//Deleting a node means returning NULL to it's parents.

        }   
      
        //it was not the value to be deleted.

        return root;//Just return it too it's parents.So,that it remains in the linkage with it's parents.

    }

    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        
        vector<TreeNode*>result;

        unordered_set<int>st;
        for(auto it : to_delete) {
            st.insert(it);
        }

        TreeNode* temproot = deleteHelper(root,st,result);
        
        if(temproot) {
            result.push_back(temproot);
        }

        return result;

        //TC : O(n)
        //SC : O(n)

    }
};