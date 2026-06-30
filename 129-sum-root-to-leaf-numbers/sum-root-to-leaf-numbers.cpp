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

    void mydfssum(TreeNode* root,int &sum,vector<int>&temp,vector<vector<int>>&ans) {

        if(root == NULL) {
            return;
        }

        sum += root->val;
        temp.push_back(root->val);

        if(root->left == NULL && root->right == NULL) {
            ans.push_back(temp);
        }

        mydfssum(root->left,sum,temp,ans);
        mydfssum(root->right,sum,temp,ans);

        sum -= root->val;
        temp.pop_back();

        return;

    }

    int sumNumbers(TreeNode* root) {

        vector<vector<int>>ans;

        int sum = 0;
        vector<int>temp;
        mydfssum(root,sum,temp,ans);
        int final_Sum = 0;

        for(int i=0;i<ans.size();i++) {

            vector<int>temp1 = ans[i];
            int sum1 = 0;
            for(int j = 0; j<temp1.size();j++) {
                sum1 += (temp1[j]*pow(10,temp1.size()-j-1));
            }       
            final_Sum += sum1;
        }

        return final_Sum;

    }
};