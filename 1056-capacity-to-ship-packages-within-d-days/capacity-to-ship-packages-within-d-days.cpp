class Solution {
public:

    bool can_Ship_Packages(long long int weighting_capacity,vector<int>&weights,int days,long long int available_total)
    {//21,5,55
        
        int n=weights.size();
        long long int total_shipped_packages = 0;
        long long int current_sum = 0;
        
        for(int i = 0; i < n ;i ++)
        {   //i=0;i=6;i=7;7;8;9;9
        
            if( current_sum + weights[i] <= weighting_capacity  && days>0)
            current_sum += weights[i]; //1+2+3+4+5+6==21//7+8=15//9+10

            else
            { 
                if(days>0)
                {
                    
                    total_shipped_packages += current_sum;//21+15==36
                    current_sum = 0;//0//0

                    days--;//4  //3 
                    i -= 1;//6 //8
                }
            }
            if(days == 0)
            {
                break;
            }

            if(i == n - 1  && current_sum<=weighting_capacity)
            {
                total_shipped_packages += current_sum;//36+19==55
            }
            //i=7;9
        }
        return total_shipped_packages == available_total;//
    }

    int shipWithinDays(vector<int>& weights, int days) {

        long long int D = days;
        long long int available_total_packages = 0;
        int n=weights.size();
        
        for(int i = 0; i < n ; i++)
        {
            available_total_packages += weights[i];
        }

        long long int low = 1;//1
        long long int high = available_total_packages;//
        long long int mid = -1;
        long long int ans = -1;

        while(low <= high)
        {       
            mid = low + (high - low)/2;//21

            if(can_Ship_Packages(mid,weights,D,available_total_packages))
            {
                ans  = mid;//28
                high = mid - 1;//27
            }
            else
            {
                low = mid + 1;//15
            }
        }
        return ans;
    }
};