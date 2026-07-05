class Solution {
public:

    int garbageCollection(vector<string>& garbage, vector<int>& travel) {

        int last_metal = -1;
        int last_paper = -1;
        int last_glass = -1;

        int n = garbage.size();

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
        }


        vector<int>prefix_travel(n,0);

        //travel_prefix[i] stores the total time needed to travel from 0th index to ith index.

        for(int i = 1;i < prefix_travel.size();i++) {
            prefix_travel[i] = travel[i-1] + prefix_travel[i-1];
        }

        int min_time = 0;

        for(int i = 0;i <= last_paper;i++){
            if(garbage[i].find('P')!=string::npos) {
                
                for(int j = 0;j < garbage[i].size();j++) {
                    if(garbage[i][j] == 'P')
                    min_time++;
                }
            }
        }

        if(last_paper!=-1) {
            min_time += prefix_travel[last_paper];
        }

        for(int i = 0;i <= last_glass;i++){

             if(garbage[i].find('G')!=string::npos) {
                
                for(int j = 0;j < garbage[i].size();j++) {
                    if(garbage[i][j] == 'G')
                    min_time++;
                }
            }
        }
        if(last_glass!=-1) {
            min_time += prefix_travel[last_glass];
        }

        for(int i = 0;i <= last_metal;i++){

             if(garbage[i].find('M')!=string::npos) {
                
                for(int j = 0;j < garbage[i].size();j++) {
                    if(garbage[i][j] == 'M')
                    min_time++;
                }
            }
        }
        
        if(last_metal!=-1) {
            min_time += prefix_travel[last_metal];
        }

        return min_time;

        //TC : O(n)
        //SC : O(1)
        
    }
};