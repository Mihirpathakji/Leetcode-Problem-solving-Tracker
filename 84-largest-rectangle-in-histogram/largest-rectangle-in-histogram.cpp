class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {

        vector<int>next_smaller_right(heights.size(),heights.size());
        stack<int>st1;
        for(int i = 0; i< heights.size(); i++)
        {   
            while(!st1.empty() && heights[i] < heights[st1.top()])
            {
                next_smaller_right[st1.top()] = i;
                st1.pop(); 
            } 
            st1.push(i);
        }

        vector<int>next_smaller_left(heights.size(),-1);
        stack<int>st2;
        for(int i = heights.size()-1; i>= 0; i--)
        {
            while(!st2.empty() && heights[i] < heights[st2.top()])
            {
                next_smaller_left[st2.top()] = i;
                st2.pop();
            }
            st2.push(i);
        }

        vector<int>final_ans(heights.size());
        for(int i = 0 ; i< final_ans.size(); i++)
        {
            final_ans[i] = (next_smaller_right[i] - next_smaller_left[i] -1)*heights[i];
        }

        int maxi = *max_element(final_ans.begin(),final_ans.end());

        return maxi;
    }
};