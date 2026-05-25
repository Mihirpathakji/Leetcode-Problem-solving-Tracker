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

    int minDepth(TreeNode* root) {

        if(root == NULL)
        {
            return 0;
        }

        //BFS -> First node which is Leaf node , The level of that leaf node is the Minimum height.

        queue<TreeNode*>q;

        q.push(root);

        int min_Depth = 1;  

        while(!q.empty())
        {
            int n = q.size();
            while(n--)
            {
                TreeNode* temp = q.front();
                q.pop();
                if(temp->left == NULL && temp->right == NULL)
                {
                    return min_Depth;
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
            min_Depth++;
        }

        return -1;

        //TC : O(n).
        //SC : O(n).

    }
};