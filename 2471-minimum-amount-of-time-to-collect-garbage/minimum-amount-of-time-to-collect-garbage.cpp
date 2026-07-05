class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {

        int last_metal = -1;
        int last_paper = -1;
        int last_glass = -1;

        int n = garbage.size();

        for(int i = 0;i < n;i++) {

            if(garbage[i].find('P')!=string::npos) {
                last_paper = i;//1 2
            }
            
            if(garbage[i].find('G')!=string::npos) {
                last_glass = i;//0 2 3
            }
            
            if(garbage[i].find('M')!=string::npos) {
                last_metal = i;//-1
            }
        }

        int min_time = 0;

        for(int i = 0;i <= last_paper;i++){
            if(garbage[i].find('P')!=string::npos) {
                
                for(int j = 0;j < garbage[i].size();j++) {
                    if(garbage[i][j] == 'P')
                    min_time++;
                }

                if(i!=0) {
                    min_time += travel[i-1];
                }

            }
            else if(i!=0){
                min_time += travel[i-1];
            }
        }

        for(int i = 0;i <= last_glass;i++){

             if(garbage[i].find('G')!=string::npos) {
                
                for(int j = 0;j < garbage[i].size();j++) {
                    if(garbage[i][j] == 'G')
                    min_time++;
                }

                if(i!=0) {
                    min_time += travel[i-1];
                }

            }
            else if(i!=0){
                min_time += travel[i-1];
            }
        }

        for(int i = 0;i <= last_metal;i++){

             if(garbage[i].find('M')!=string::npos) {
                
                for(int j = 0;j < garbage[i].size();j++) {
                    if(garbage[i][j] == 'M')
                    min_time++;
                }

                if(i!=0) {
                    min_time += travel[i-1];
                }

            }
            else if(i!=0){
                min_time += travel[i-1];
            }
        
        }

        return min_time;

        //TC : O(n)
        //SC : O(1)
        
    }
};