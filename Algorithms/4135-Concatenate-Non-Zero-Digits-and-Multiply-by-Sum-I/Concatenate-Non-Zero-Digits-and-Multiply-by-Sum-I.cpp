class Solution {
public:
    long long sumAndMultiply(int n) {
        vector<int> newd;
        int temp = n;
        while(temp>0){
            int rem = temp%10;
            if(rem!=0){
                newd.push_back(rem);
            }
            temp = temp/10;
        }
        int sum = accumulate(newd.begin(),newd.end(),0);
        long long ans = 0;
        for(int i = newd.size() - 1; i >=0;i--){
            ans = ans*10 + newd[i];
            // cout << "bhosdi";
        }
        return ans * sum;
    }
};