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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {

        vector<vector<int>>ans;
        if(root == NULL)
        {
            return ans;
        }   

        queue<TreeNode*>q;
        q.push(root);

        int level = 0;

        while(!q.empty())
        {
            int n = q.size();
            vector<int>temp1;
            while(n--)
            {
                TreeNode*temp =  q.front();
                q.pop();

                temp1.push_back(temp->val);
                if(temp->left)
                {
                    q.push(temp->left);
                }
                if(temp->right)
                {
                    q.push(temp->right);
                }
            }

            if(level % 2 == 0) 
            {
                ans.push_back(temp1);
            }

            else
            {
                reverse(temp1.begin(),temp1.end());
                ans.push_back(temp1);
            }
            level++;

        }
        return ans;
    }
};