class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {

        sort(asteroids.begin(),asteroids.end());//[3,5,9,19,21]
        long long mass1 = mass;

        bool flag = true;
        for(int i = 0 ; i < asteroids.size(); i++)
        {
            if(asteroids[i] <= mass1)
            {
                mass1 += asteroids[i];//13 18 27 32
            }
            else
            {
                flag = false;
                break;
            }
        }
        
        return flag;
        
    }
};