class Solution {
public:
    int minimumRefill(vector<int>& plants, int capacityA, int capacityB) {
       int tempA=capacityA;
       int tempB=capacityB; 
       int n=plants.size();
       int refill_count=0;
       int alice=0;
       int bob=n-1;
       while(alice<=bob)
       {    
            if(alice==bob)
            {
                if(capacityA>capacityB && capacityA>=plants[alice])
                {
                    capacityA-=plants[alice];
                    alice++;
                }
                else if(capacityB>capacityA && capacityB>=plants[alice])
                {
                    capacityB-=plants[alice];
                    alice++;
                }
                else if(capacityA==capacityB && capacityA>=plants[alice])
                {
                    capacityA-=plants[alice];
                    alice++;
                }
                else
                {   refill_count++;
                    capacityA=tempA;
                    capacityA-=plants[alice];
                    alice++;
                }
            }
            else if(capacityB>=plants[bob] && capacityA<plants[alice])
            {   
                refill_count++;
                capacityA=tempA;
                capacityA-=plants[alice];
                alice++;
                capacityB-=plants[bob]; 
                bob--;
            }
            else if(capacityA>=plants[alice] && capacityB<plants[bob])
            {
                refill_count++;
                capacityB=tempB;
                capacityB-=plants[bob];
                bob--;
                capacityA-=plants[alice];
                alice++;
            }
            else if(capacityA>=plants[alice] && capacityB>=plants[bob])
            {   
                capacityA-=plants[alice];
                capacityB-=plants[bob];
                alice++;//1
                bob--;//3
            }
            else if(capacityA<plants[alice] && capacityB<plants[bob])
            {
                refill_count+=2;
                capacityA=tempA;
                capacityB=tempB;
                capacityA-=plants[alice];
                capacityB-=plants[bob];
                alice++;
                bob--;
            }
       }
       return refill_count; 
        //TC:O(n)
        //SC:O(1)
    
    }
};