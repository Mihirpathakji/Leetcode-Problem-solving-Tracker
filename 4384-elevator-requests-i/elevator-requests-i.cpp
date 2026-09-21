class Solution {
public:
    int elevatorRequests(int n, vector<int>& requests) {

        long long total_time = 0;
        long long lst = 0;

        for(int i = 0;i < requests.size();i++) {

            total_time += abs(requests[i]-lst);
            lst = requests[i];
        }

        return total_time;
        
        
    }
};