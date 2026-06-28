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

    bool isCompleteTree(TreeNode* root) {

        queue<TreeNode*>q;
        q.push(root);
       
        bool past_null = false;

        while(!q.empty()) {

            int n = q.size();

            while(n--) {

                TreeNode* temp = q.front();
                q.pop();

                if(temp == NULL) {
                    past_null = true;
                    continue;
                }
                else {
                    if(past_null) {
                        return false;
                    }
                }

                q.push(temp->left);
                q.push(temp->right);
            }
        }

        return true;

        //TC : O(n)
        //SC : O(1)
        
    }
};