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
    vector<int> rightSideView(TreeNode* root) {

        vector<int>ans;
        if(root == NULL)
        {
            return ans;
        }

        queue<TreeNode*>q;
        q.push(root);

        while(!q.empty())
        {
            //Level wise keep a track of last node of the every level.  
            int n = q.size();
            int original = n;//2 4 ->1 
            //original = 4
            //n        = 0 ->push

            while(n--)
            {
                TreeNode* temp = q.front();
                q.pop();

                if(n == 0)
                {
                    ans.push_back(temp->val);
                }    

                if(temp->left)
                {
                    q.push(temp->left);
                }

                if(temp->right)
                {
                    q.push(temp->right);
                }
            }
        }
        return ans;

    }
};