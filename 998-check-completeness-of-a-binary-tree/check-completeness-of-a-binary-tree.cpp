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

        int levels = 0;

        queue<TreeNode*>q;

        q.push(root);//1

        while(!q.empty())
        {
            int n = q.size();

            while(n--)
            {
                TreeNode* temp = q.front();
                q.pop();

                if(temp->left) {
                    q.push(temp->left);
                }       

                if(temp->right) {
                    q.push(temp->right);
                }  
            }
            levels++;//1 
        } 

        int last_level = levels-1;//0

        int curr_level = 0;//0

        vector<int>ans;
        q.push(root);//[100]
        while(!q.empty())
        {
            int n = q.size();//1
            int counts = 0;
            while(n--)
            {
                TreeNode* temp = q.front();//100
                q.pop(); 
                
                if(curr_level == last_level && temp!=NULL) {
                    ans.push_back(temp->val);//1
                }

                if(temp) {
                    counts++;//1
                } 
               
                if(temp && temp->left) {
                    q.push(temp->left);
                }       
                else if(temp && !temp->left && curr_level == last_level-1) {
                    q.push(NULL);
                }
      
                if(temp && temp->right) {
                    q.push(temp->right);
                }  
                
                else if(temp && !temp->right && curr_level == last_level -1) {
                    q.push(NULL);
                }

                if(temp == NULL && curr_level == last_level) {
                    ans.push_back(-1);
                }
            }

            if(counts!=pow(2,curr_level) && curr_level!=last_level) {
                return false;
            }

            curr_level++;//1

            if(curr_level-1 == last_level) {

                int n1 =  ans.size();
                int index = -1;
                bool flag = false;

                for(int i = 0;i < n1;i ++)
                {
                    if(ans[i] == -1) {
                        index = i;
                        flag = true;
                        break;
                    }
                }

                for(int i = index+1;i< ans.size();i++)
                {
                    if(ans[i]!=-1 && flag)
                    return false;
                }
            }   
        }

        return true;
        
    }
};