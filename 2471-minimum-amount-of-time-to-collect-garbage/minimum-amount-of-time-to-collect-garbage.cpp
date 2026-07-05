class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        
        int metal_time = 0;
        int paper_time = 0;
        int glass_time = 0;

        set<int>glass;
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

            auto it =  glass.end();
            it--;
            int last = *it;//3

            for(int i = 0;i <= last;i++) {
                
                if(glass.find(i)!=glass.end()) {
                    
                    for(int j = 0;j <garbage[i].size() ;j++) {
                        if(garbage[i][j] == 'G') {
                            min_time++;//1 4 10 
                        }
                    } 

                    if(i!=0) {
                        min_time += travel[i-1];//8 13
                    }
                }
                else {

                    if(i!=0) {
                        min_time += travel[i-1];//+=2 // 3 
                    }
                }
                
            }        
        }

        
        if(paper.size() >= 1) {
            
            auto it = paper.end();
            it--;
            int last = *it;//2
            
            for(int i = 0;i <= last;i++) {
                
                if(paper.find(i)!=paper.end()) {
                    for(int j = 0;j <garbage[i].size() ;j++) {
                        if(garbage[i][j] == 'P') {
                            min_time++;//14 17
                        }
                    } 

                    if(i!=0) {
                        min_time += travel[i-1];//16  21
                    }
                }
                else {

                    if(i!=0) {
                        min_time += travel[i-1];
                    }
                }
            }
            
        } 

        
        if(metal.size()>=1) {

            auto it =  metal.end();
            it--;
            int last = *it;

            for(int i = 0;i <= last ;i++) {
                
                if(metal.find(i)!=metal.end()) {
                    for(int j = 0;j <garbage[i].size() ;j++) {
                        if(garbage[i][j] == 'M') {
                            min_time++;
                        }
                    } 

                    if(i!=0) {
                        min_time += travel[i-1];
                    }
                }
                else if(i!=0) {
                    min_time += travel[i-1];
                }
            } 
        }

        return min_time;

        //TC : O(n*logn)
        //SC : O(n)

    }
};