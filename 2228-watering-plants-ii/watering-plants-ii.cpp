class Solution {
public:
    int minimumRefill(vector<int>& plants, int capacityA, int capacityB) {
       
        int n = plants.size();
        int ca = capacityA;
        int cb = capacityB;

        int alice = 0;
        int bob = n-1;
        int refill_count = 0;

        while(alice < bob) {

            if(ca < plants[alice]) {
                ca = capacityA;
                refill_count++;
            }

            if(cb < plants[bob]) {
                cb = capacityB;
                refill_count++;
            }

            ca -= plants[alice];
            cb -= plants[bob];

            alice++;
            bob--;
        }

        if(alice == bob) {
            if(ca < plants[alice] && cb < plants[bob]) {
                refill_count++;
            }
        }

        return refill_count;
        
    }
};