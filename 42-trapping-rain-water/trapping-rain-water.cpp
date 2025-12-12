class Solution {
public:
    int trap(vector<int>& heights) {

        int n=heights.size();
        vector<int>prefix_max(n);
        vector<int>suffix_max(n);
    
        //computing prefix_max[] and suffic_max[]:

        //prefix_max[]:
        prefix_max[0]=heights[0];
        for(int i=1;i<n;i++)
        {
            prefix_max[i]=max(prefix_max[i-1],heights[i]);
        }//O(n)

        //suffix_max[]:
        suffix_max[n-1]=heights[n-1];
        for(int i=n-2;i>0;i--)
        {
            suffix_max[i]=max(suffix_max[i+1],heights[i]);
        }//O(n)
        int total_units=0;
        for(int i=1;i<n-1;i++)
        {
            if(heights[i]<prefix_max[i] && heights[i]<suffix_max[i])
            {
                //then only water can be logged.
                total_units+=min(prefix_max[i],suffix_max[i])-heights[i];
            }
        }//O(n)
        return total_units;
    
        //TC:O(3*n)=O(n)
        //SC:O(2*n)=O(n)
    }
};