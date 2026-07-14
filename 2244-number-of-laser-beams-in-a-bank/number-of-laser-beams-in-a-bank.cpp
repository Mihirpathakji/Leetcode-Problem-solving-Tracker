class Solution {
public:
    int numberOfBeams(vector<string>& bank) {

        int m = bank.size();
        int n = bank[0].size();

        vector<int>security_devices(m);

        for(int i = 0;i < m;i++) {
            for(int j = 0;j < n;j++) {
                if(bank[i][j] == '1') {
                    security_devices[i]++;
                }
            }
        }

        long long prev = security_devices[0];
        long long ans = 0;

        for(int i = 1;i < m;i++) {

            if(security_devices[i]!=0 && prev == 0) {
                prev = security_devices[i];
            }
            else if(security_devices[i]!=0 && prev!=0) {
                ans += (security_devices[i]*prev);
                prev = security_devices[i];//since the curr is non zero.So the for next one this serves as preivous.
            }
            else if(security_devices[i] == 0) {
                continue;
            }
        }

        return ans;
        
    }
};