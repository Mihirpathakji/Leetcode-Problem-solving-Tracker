class Solution {
public:
    int wateringPlants(vector<int>& plants, int capacity) {
        int n=plants.size();
        int ca=capacity;//4
        int i=0;//starting index to water the plants.
        int steps=0;
        while(i<n)
        {//i=0
            if(ca<plants[i])
            {
                //go back to the river and came back to the Next Position.
                steps+=(2*i+1);//10 19 30
                ca=capacity;//4 0 4 2 4 
            }
            else
            {
                steps++;//1 2 3 
            }
            ca-=plants[i];//3 2 1 0 1
            i++;
            //i==1;2;3;4;5;6
        }   
        return steps;

        //TC:O(n)
        //SC:O(1)
    }
};