class Solution {
public:
    int gcd(int a,int b){
        for(int i = a ; i>=1;i--){
            if(a%i==0 && b%i==0)return i;
        }
        return 1;
    }
    int findGCD(vector<int>& nums) {
       int min_arr = INT_MAX;
       int max_arr = INT_MIN;
       for(int i = 0 ; i < nums.size() ; i++){
        if(nums[i] > max_arr)max_arr = nums[i];
        if(nums[i] < min_arr)min_arr = nums[i];
       }
       return gcd(min_arr,max_arr);
    }
};