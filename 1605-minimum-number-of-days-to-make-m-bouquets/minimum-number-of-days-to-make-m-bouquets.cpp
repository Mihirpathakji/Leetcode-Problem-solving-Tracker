class Solution {
public:

    bool canMakemBouquets(int waiting_days,int k,vector<int>&bloomDay,int m)
    {   
        int Bouquets_made=0;//0
        int adjacent_flowers=0;//0
        for(int i=0;i<bloomDay.size();i++)
        {//i==3 ;i=4;i=5
            if(bloomDay[i]<=waiting_days)
            {
                adjacent_flowers++;//1+1=2+1=3//1//1+1==2//3//1//2//1//2//3//1 2 3//1//3//1
            }
            else
            {
                adjacent_flowers=0;
            }
            if(adjacent_flowers==k)
            {
                Bouquets_made++;//1.Now to make a new bouquet new set of adjacent flowers needed//1//1//1//2//1
                adjacent_flowers=0;//0//0//0//0//0//0
            }
        }
        return Bouquets_made>=m;

    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        int n=bloomDay.size();
        //Apply binary search  on the number of days :-
        long long int low=1;//minimum no. of days 
        long long int high=*max_element(bloomDay.begin(),bloomDay.end());//maximum no. of days 
        long long int mid;
        long long int ans=-1;

        //Apply Binary search on the number of days:

        while(low<=high)
        {
            mid=low+(high-low)/2;//9

            if(canMakemBouquets(mid,k,bloomDay,m))
            {
                ans=mid;//12
                high=mid-1;//decrease the waiting days;11
            }
            else
            {
                low=mid+1;//increase the waiting days//7
            }
        }
    return ans;
    //mid=6;mid=7+12==19/2=9 ->low=10 high=12 mid=11;low=12 high=12 mid=12
    //TC:O(n*log(max_Days))
    //SC:O(1)
    }
};