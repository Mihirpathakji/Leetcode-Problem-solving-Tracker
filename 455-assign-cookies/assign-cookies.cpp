class Solution {  
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {

        long long max_child = 0;

        //Greedily Assign 

        int n = g.size();
        int m = s.size();

        sort(g.begin(),g.end());
        sort(s.begin(),s.end());

        int i = 0;
        int j = 0;

        while(i < n && j < m)
        {
            if(g[i] <= s[j])
            {
                max_child++;
                i++;
            }
            j++;
        }   

        return max_child; 

        //TC: O(max(nlogn,mlogm))
        //SC: O(1)

    }
};