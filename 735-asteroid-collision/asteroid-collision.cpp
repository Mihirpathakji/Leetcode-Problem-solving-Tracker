class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        
        int n = asteroids.size();
        stack<int>st;
        vector<int>ans;
        
        //Process all elements:

        int i = 0;
        
        while(i < n) {

            //When did collision does not happen??1.If stack is empty or Condn for collision does not met.

            //Case1 : This asteroid wont collide.
            if(st.empty() || !(st.top() > 0 && asteroids[i] < 0 )) {
                st.push(asteroids[i]);
                //this asteroids[i] will surely not collide.
                i++;//1
            }

            //Case2 : This asteroid wont collide. 
            else {

                //Collision will surely Occur.Lets determine the direction of the resultant collision.


                if(abs(st.top()) > abs(asteroids[i])) {
                    i++;//st.top() has larger magnitude than the -ve asteroids[i].i.e asteroids[i] would get destroyed.
                }

                else if(abs(asteroids[i]) > st.top()){
                    //st.top() has smaller magnitude than the negative asteroids[i].
                    st.pop();//Do not push the asteroids[i].Let it keep popping the elements until it can. 
                }
                else {
                    //both explodes.
                    st.pop();
                    i++;
                }
            }

        }
      
        while(!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }

        reverse(ans.begin(),ans.end());

        return ans;

        //TC : O(n)
        //SC : O(n)

    }
};