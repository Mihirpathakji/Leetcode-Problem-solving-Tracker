class StockSpanner {
public:

    vector<int>arr;

    StockSpanner() {
        
    }
    
    int next(int price) {
        
        arr.push_back(price);//[100 80]

        int n = arr.size();
        int count = 0;

        //[100 80 85 70 65 82]

        for(int i = n - 1; i >= 0 ;i--)
        {
            if(arr[i] <= price)
            {
                count++;//1 2 3         
            }
            else
            {
                //Now there is no (arr[i] <= price) CONSECUTIVELY.  
                break;
            }
        }
        return count;

    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */