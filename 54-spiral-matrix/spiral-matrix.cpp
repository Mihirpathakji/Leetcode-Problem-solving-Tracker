class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
      int top=0;//row at the top
      int m=matrix.size();
      int bottom=m-1; //row at the bottom 
      int left=0;//coulumn at the left 
      int n=matrix[0].size();//no. of the coulumns.
      int right=n-1;
      vector<int>ans;
      while(top<=bottom && left<=right)
      {
        //1.Print the top-row:(condition for the top gets already checked by the while loop condition)
        for(int i=left;i<=right;i++)
        {
            ans.push_back(matrix[top][i]);
        }
        top++;//1

        //2. Print the right coulumn from top to bottom.Although top had changed to new value but the constraint of the while loop that the (top<=bottom) gots checked in the for loop hence no need to write an extra if (condition) for the same .and the right is not even changed till yet .and the old right already got checked from the while loop condition.
        for(int i=top;i<=bottom;i++)
        {
            ans.push_back(matrix[i][right]);
        }
        right--;

        //3.Print the bottom row from right to left:Here the top was changed after top++;May possible top!<=bottom and that condition is not getting checked in the for loop condition.check it manually:Becase top is changed may possible top>bottom than you can;t access the bottom element arr"[bottom]"[i]
        if(top<=bottom)
        {    
            for(int i=right;i>=left;i--)
            {
                ans.push_back(matrix[bottom][i]);
            }
            bottom--;//5--
        }

        //4.Print the left-coulumn  from bottom to top.Here the condition that top<=bottom is checked int the for loop condition itslef.but now the right was also changed(right-- earlier).And the condition that the left<=right is not checked in the for loop condition.Check it Manually.
        if(left<=right)
        {      
            for(int i=bottom;i>=top;i--)
            {
                ans.push_back(matrix[i][left]);
            }
            left++;
        }
      }
      return ans;

    //TC:O(m*n)  All elements==m*n are Traversed.
    //SC:O(m*n)  Pushing all elements =m*n in it

    }
};