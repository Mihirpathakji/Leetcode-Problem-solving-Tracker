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
    
    bool are_parents_same(TreeNode* root,int x,int y)
    {   

        //Base case :

        if(root == NULL)
        {
            return false;//It cannot be the parent of anyone.NULL Node cannot be parent of both.
        }

        if(root->left && root->right && ((root->left->val == x && root->right->val == y) || (root->right->val == x && root->left->val == y )))
        {
            return true;
        }

        //Check if the any node = root on it's left subtree has two childs as a and b or not.
        bool left_check = are_parents_same(root->left,x,y);
        bool right_check = are_parents_same(root->right,x,y);  

        return left_check || right_check;

    }

    bool isCousins(TreeNode* root, int x, int y) {  

        //1.Check if two nodes have the same depth i.e are at the same level or not :
        int l1 = -1;
        int l2 = -1;

        int level = 1;
        queue<TreeNode*>q;
        q.push(root);

        while(!q.empty())
        {
            int n = q.size();
            while(n--)
            {
                TreeNode* temp = q.front();
                q.pop();

                if(temp->left)
                {
                    if(temp->left->val == x)
                    {
                        l1 = level;
                    }
                    if(temp->left->val == y)
                    {
                        l2 = level;
                    }
                    q.push(temp->left);
                }
                if(temp->right)
                {
                    if(temp->right->val == y)
                    {
                        l2 = level;
                    }
                    if(temp->right->val == x)
                    {
                        l1 = level;
                    }
                    q.push(temp->right);
                }
            }
            level++;
        }

        if(l1!=l2)
        {   
            return false;
        }
        if(l1!=-1)
        {

            //2.Check that both have the different Parent.

            //Made a recursive function that checks if two parents are different or not:

            if(are_parents_same(root,x,y))
            {
                return false;
            }
            return true;
        }
        return false;
    }
};