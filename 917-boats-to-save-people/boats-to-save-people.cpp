class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {

        //sorting + two pointer.l = 0;r = n-1;

        int n = people.size();
        vector<bool>are_placed(n,false);

        sort(people.begin(),people.end());

        int l = 0;
        int r = n-1;
        int boats = 0;

        while(l < r)
        {   
            if(l == r)
            {
                boats++;
                are_placed[l] = true;
                l++;
                r--;
            }

            else if((people[l] + people[r]) <= limit)
            {
                boats++;
                are_placed[l] = true;
                are_placed[r] = true;
                l++;
                r--;
            }
            else
            {
                r--;
            }
        }

        for(int i= 0;i<are_placed.size();i++)
        {
            if(are_placed[i] == false)
            {
                boats++;
            }
        }

        return boats;
        
    }
};