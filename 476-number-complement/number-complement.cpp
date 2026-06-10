class Solution {
public:
    int findComplement(int num) {
        
        //XOR Every bit by 1.
        vector<int>binary;
        while(num > 0)
        {   
            int remainder = num % 2;//[1 0 1]
            binary.push_back(remainder);//[1 0 1]
            num/=2;//2 1 0
        }
        reverse(binary.begin(),binary.end());

        for(int i = 0 ; i < binary.size() ; i++)
        {
            binary[i] ^= 1;
        }
      
        //[0 1 0]

        //Binary to decimal.

        long long int p2 = 1;
        long long int sum = 0;
        for(int i = binary.size()-1;i >=0 ;i--)
        {
            if(binary[i] == 1)
            {   
                sum += (binary[i])*p2;
            }
            p2 *= 2;//2
        }

        return sum;
        
    }
};