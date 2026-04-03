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
    vector<vector<int>> levelOrder(TreeNode* root) {
        
        vector<vector<int>>final_ans;
        queue<TreeNode*>q;

        if(root == NULL)
        {
            return {};
        }

        q.push(root);

        while(!q.empty())
        {
            
            vector<int>ans;
            int size = q.size();
        
            for(int i = 0 ; i < size; i++)
            {
                root = q.front();
                ans.push_back(root->val);
                q.pop();

                if(root->left)
                {
                    q.push(root->left);
                }   
                

                if(root->right)
                {
                    q.push(root->right);
                }

            }
            
            final_ans.push_back(ans);

        }

        return final_ans;

        //TC:O(N)
        //SC:O(N)

    }
};