class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        
        int metal_time = 0;
        int paper_time = 0;
        int glass_time = 0;

        vector<long long>travel1(travel.begin(),travel.end());

        set<int>glass;//{0,2,3}
        set<int>paper;
        set<int>metal;

        int n = garbage.size();

        for(int i = 0;i < n;i++) {
           
            string temp = garbage[i];

            if(temp.find('P')!=string ::npos) {
                paper.insert(i);
            }
            
            if(temp.find('G')!=string ::npos) {
                glass.insert(i);
            }
            
            if(temp.find('M')!=string ::npos) {
                metal.insert(i);
            }
            
        }

        long long min_time = 0;

        if(glass.size() >= 1) {

            auto it =  glass.end();//{0,2,3}
            it--;
            int last = *it;//3

            for(int i = 0;i <= last;i++) {

                bool flag = false;
                
                if(glass.find(i)!=glass.end()) {
                    for(int j = 0;j <garbage[i].size() ;j++) {
                        if(garbage[i][j] == 'G') {
                            min_time++;//
                        }
                    } 

                    if(i!=0 && !flag) {
                        min_time += travel1[i-1];// 
                        flag = true;
                    }
                }
                else {

                    if(i!=0 && !flag) {
                        min_time += travel1[i-1];// 
                        flag = true;
                    }
                }
                
            }        
        }

        
        if(paper.size() >= 1) {
            
            auto it = paper.end();
            it--;
            int last = *it;
            
            for(int i = 0;i <= last;i++) {
                
                bool flag = false;

                if(paper.find(i)!=paper.end()) {
                    for(int j = 0;j <garbage[i].size() ;j++) {
                        if(garbage[i][j] == 'P') {
                            min_time++;//2 10
                        }
                    } 

                    if(i!=0 && !flag) {
                        min_time += travel1[i-1];
                        flag = true;
                    }
                }
                else {

                    if(i!=0 && !flag) {
                        min_time += travel1[i-1];// 
                        flag = true;
                    }
                }
            }
            
        } 

        
        if(metal.size()>=1) {

            auto it =  metal.end();
            it--;
            int last = *it;

            for(int i = 0;i <= last ;i++) {
                
                bool flag = false;
                if(metal.find(i)!=metal.end()) {
                    for(int j = 0;j <garbage[i].size() ;j++) {
                        if(garbage[i][j] == 'M') {
                            min_time++;
                        }
                    } 

                    if(i!=0 && !flag) {
                        min_time += travel1[i-1];
                        flag = true;
                    }
                }
                else if(i!=0) {
                    min_time += travel1[i-1];
                    flag = true;
                }
            } 
        }

        return min_time;


    }
};