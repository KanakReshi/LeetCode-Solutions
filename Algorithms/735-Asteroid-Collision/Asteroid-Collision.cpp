class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack <int>st;
        vector<int>result;
        int len = asteroids.size();
        for(int i = 0;i<len;i++){
            if(!st.empty() && asteroids[i]<0){
                if(!st.empty() &&st.top() > 0){
                    while(!st.empty() && st.top()>0 && st.top() < abs(asteroids[i])){
                        st.pop();
                    }
                    if(st.empty() || st.top()<0){
                        st.push(asteroids[i]);
                    }
                    if(!st.empty() && st.top() == -asteroids[i]){
                        st.pop();
                        continue;
                    }
                    else{
                        continue;
                    }
                }
                else{
                    st.push(asteroids[i]);
                }
            }
            else{
                st.push(asteroids[i]);
            }
        }
        while(!st.empty()){
            result.push_back(st.top());
            st.pop();
        }
        reverse(result.begin(),result.end());
        return result;

    }
};