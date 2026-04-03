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

        vector<vector<int>>ans;

        queue<TreeNode*>q;
        if(root == NULL)
        {   
            return {};
        }
        
        q.push(root);//Address 
        
        while(!q.empty())
        {
            int size = q.size(); //  2 
            vector<int> answer;
            while(size--) {
                
                auto root = q.front();//20 7 
                answer.push_back(root->val);  //15 7 
                q.pop();// 15 

                if(root->left)
                {
                    q.push(root->left);//Address.
                }
                
                if(root->right)
                {
                    q.push(root->right);
                }
                
            }

            ans.push_back(answer);//3
        }

        return ans;
        
    }
};