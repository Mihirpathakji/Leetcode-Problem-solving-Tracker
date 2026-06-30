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

    void mydfssum(TreeNode* root,int& targetSum,int& sum,vector<int>& temp,vector<vector<int>>& ans) {

        //if i reached leaf node check if sum has become targetSum or not.

        if(root == NULL) {
            return;
        }
        
        if(root) {
            sum += root->val;//9 20 22
            temp.push_back(root->val);//[5,4,11,7] 
        }

        if(!root->left && !root->right && sum == targetSum) {
            ans.push_back(temp);
        }

        mydfssum(root->left,targetSum,sum,temp,ans);//N
        mydfssum(root->right,targetSum,sum,temp,ans);//N  

        sum -= root->val;
        temp.pop_back();

        return;
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {

        int sum = 0;
        vector<vector<int>>ans;
        vector<int>temp;

        mydfssum(root,targetSum,sum,temp,ans);

        return ans;
        
    }
};