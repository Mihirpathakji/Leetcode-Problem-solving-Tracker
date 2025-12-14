class Solution {
public:
    int maxArea(vector<int>& height) {

        int n=height.size();
        int start=0;
        int end=n-1;
        int max_area=INT_MIN;
        int current_area=0;

        while(start<end)
        {   
            current_area=(end-start)*min(height[end],height[start]);
            max_area=max(max_area,current_area);

            //Here in this two Pointer Technique.The width has only ONE CASE THAT IT IS ALWAYS DECREASING AFTER THE first iteration.Width of container can never increase afterby.Hence no cases can be judged based on the width.But can be judged based on the height of the bars since the height at the start and at the end point have different value.Whereas the width dosent.What our Target is to Maximize the Area.Since the width is Always Decreasing hence greedily to increase the OVERALL AREA=WIDTH*HEIGHT the width decreases and hence to increase the area the height must be increase i.e the taller height should not be changed they should be retained and the smaller heights must be changed ,Greedily to increase height
            //case1:
            if(height[start]<height[end])
            {
                //hieght[end] is larger one so retained it.
                start++;//increment the height
            }
            else if(height[start]>height[end])
            {
                //height[start] is Larger one so retained it 
                end--;
            }
            else
            {
                //both the height[start] and height[end] are equal.But inorder to get the next Area we need to change atleast any of the one pointer
                start++;
            }
        }
        return max_area;

     //TC:O(n)
     //SC:O(1) 
    }
};