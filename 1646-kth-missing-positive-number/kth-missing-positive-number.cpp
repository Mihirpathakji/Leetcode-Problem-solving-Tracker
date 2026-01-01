class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int i = 0;
        int num = 1;//1
        while(k)
        {
            if(i<arr.size() && arr[i] == num)
            {
                i++;//1 2 3 4
            }
            else
            {
                k--;// 1 0
            }
            num++;//2 3 4 5 6 7 
        }
        return num-1;

        //TC:O(arr.size()+k)
        //SC:O(1)
    }
};