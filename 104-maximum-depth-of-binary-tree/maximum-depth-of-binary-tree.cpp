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
    int maxDepth(TreeNode* root) {
              
        //Level order Traversal:
        
        queue<TreeNode*>q;

        if(root == NULL)
        {
            return 0;
        }
        
        q.push(root);//[NULL]
        
        vector<vector<int>>levels;
        
        while(!q.empty())
        {
            vector<int>ans;
            int size = q.size();//1 
            
            for(int i = 0; i < size; i++)
            {//0 <1
                //q = ""
                root = q.front();//NULL
                ans.push_back(root->val);//[1]
                q.pop();//
                
                if(root->left)
                {
                    q.push(root->left);
                }
                
                if(root->right)
                {
                    q.push(root->right);
                }
                
            }
            
            levels.push_back(ans);//[[1] [2 3] [4 10 5 ] [6 7] ] //[1]
        }
        
        return levels.size();
        //TC:O(N)
        //SC:O(N)
        
    }
};