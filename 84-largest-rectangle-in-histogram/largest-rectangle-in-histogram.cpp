class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {

        //Compute the index of the next smaller element on right for each :
        vector<int>next_smaller_right(heights.size(),heights.size());
        stack<int>st1;
        stack<int>st2;
        
        //Compute Index of next smaller on left for each element.
        vector<int>next_smaller_left(heights.size(),-1);

        for(int i = 0; i< heights.size(); i++)
        {   
            while(!st1.empty() && heights[i] < heights[st1.top()])
            {
                next_smaller_right[st1.top()] = i;
                st1.pop(); 
            } 
            st1.push(i);

            while(!st2.empty() && heights[heights.size()-i-1] < heights[st2.top()])
            {
                next_smaller_left[st2.top()] = heights.size() -i -1;
                st2.pop();
            }
            st2.push(heights.size()-i-1);
        }

        // if(!st1.empty())
        // {
        //     while(!st1.empty())
        //     {
        //         st1.pop();
        //     }
        // }


        //Area = Height*width.
        int maximum_area = INT_MIN;

        for(int i = 0 ;i < heights.size(); i ++)
        {
            int area_of_each = (heights[i])*(next_smaller_right[i] - next_smaller_left[i] - 1);

            maximum_area = max(maximum_area,area_of_each);
        }

        return maximum_area;

        //TC : O(n)
        //SC : O(n)
    }
};