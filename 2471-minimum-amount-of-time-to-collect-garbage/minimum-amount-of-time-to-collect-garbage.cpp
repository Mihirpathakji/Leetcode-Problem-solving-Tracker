class Solution {
public:

    int garbageCollection(vector<string>& garbage, vector<int>& travel) {

        //Separately finded out the time for travlling and time for picking up that garbage[i].

        int last_metal = -1;
        int last_paper = -1;
        int last_glass = -1;

        int n = garbage.size();

        int min_time = 0;

        for(int i = 0;i < n;i++) {
            if(garbage[i].find('P')!=string :: npos) {
                last_paper = i;
            }
            
            if(garbage[i].find('G')!=string :: npos) {
                last_glass = i;
            }
            
            if(garbage[i].find('M')!=string :: npos) {
                last_metal = i;
            }

            min_time += garbage[i].size();
        }

        vector<int>prefix_travel(n,0);
        for(int i = 1;i < prefix_travel.size();i++) {
            prefix_travel[i] =  prefix_travel[i-1] + travel[i-1];
        }
        //to reach ith : cost to reach (i-1)th + cost to go from (i-1) to ith 

        if(last_paper!=-1) {
            min_time += prefix_travel[last_paper];
        }

      
        if(last_glass!=-1) {
            min_time += prefix_travel[last_glass];
        }

        if(last_metal!=-1) {
            min_time += prefix_travel[last_metal];
        }

        return min_time;

        //TC : O(n)
        //SC : O(1)
        
    }
};