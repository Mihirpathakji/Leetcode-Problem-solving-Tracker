class Solution {
public:
        
    //Function which will give the Largest Area of the each Row as the base of the histogram.

    int maximum_area(vector<int>& heights)
    {
        //1.Next smaller on right.
        stack<int>st1;
        vector<int>nsr(heights.size(),heights.size());
        for(int i = 0 ; i < heights.size(); i++)
        {
            while(!st1.empty() && heights[i] < heights[st1.top()])
            {
                nsr[st1.top()] = i;
                st1.pop();
            }

            st1.push(i);
        }//1

        stack<int>st2;
        vector<int>nsl(heights.size(),-1);
        for(int i = heights.size()-1 ; i >=0 ; i--)
        {
            while(!st2.empty() && heights[i] < heights[st2.top()])
            {
                nsl[st2.top()] = i;
                st2.pop();
            }
            st2.push(i);
        }//-1   
        
        int maxi = INT_MIN;
        for(int i = 0 ; i< heights.size() ; i++)
        {
            maxi = max(maxi,(heights[i])*(nsr[i] - nsl[i] - 1));
        }//1*(1-(-1)) == 2

        return maxi;

    }

    int maximalRectangle(vector<vector<char>>& matrix) {

        // Every Row can be treated as the base of the histogram. We can compute the Maximum Area in each of the Histogram and finally get it's maximum . 

        int rows = matrix.size();
        int cols = matrix[0].size();

        int max_rect_area = INT_MIN;

        vector<int>temp(cols,0);

        for(int i = 0 ; i < rows ; i++)
        {
            for(int j = 0 ; j < cols ; j ++)
            {   
                if((matrix[i][j]-'0') !=0)
                {
                    temp[j] += (matrix[i][j] -'0');//[1]
                }
                else
                {
                    temp[j] = 0;
                }
            }

            max_rect_area = max(max_rect_area,maximum_area(temp));
        }

        return max_rect_area;

    }
};