class Solution {
public:

    bool can_Ship_Packages(long long int weighting_capacity,vector<int>&weights,int days,long long int available_total)
    {

        int n=weights.size();
        long long int total_shipped_packages = 0;
        long long int current_sum = 0;
        
        for(int i = 0; i < n ;i ++)
        { 
        
            if( current_sum + weights[i] <= weighting_capacity  && days>0)
            current_sum += weights[i];

            else
            {
                    total_shipped_packages += current_sum;//15+
                    current_sum = 0;

                    days--; 
                    i -= 1;
            }
            if(days == 0)
            {
                break;
            }

            if(i == n - 1 && current_sum<=weighting_capacity)
            {
                total_shipped_packages += current_sum;
            }
        
        }
        return total_shipped_packages == available_total;
    }

    int shipWithinDays(vector<int>& weights, int days) {

        long long int D = days;
        long long int available_total_packages = 0;
        int n=weights.size();
        
        for(int i = 0; i < n ; i++)
        {
            available_total_packages += weights[i];
        }

        long long int low = 1;
        long long int high = available_total_packages;
        long long int mid = -1;
        long long int ans = -1;

        while(low <= high)
        {       
            mid = low + (high - low)/2;

            if(can_Ship_Packages(mid,weights,D,available_total_packages))
            {
                ans  = mid;
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        return ans;
    }
};