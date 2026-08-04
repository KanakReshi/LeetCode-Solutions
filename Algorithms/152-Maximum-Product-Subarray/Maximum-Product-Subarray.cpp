class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int right = 1;
        int left = 1;
        int result = INT_MIN;
        int len = nums.size();
        for(int i = 0; i<len;i++){
            if(left==0)left=1;
            if(right==0)right=1;
            right = right*nums[i]; 
            left = left * nums[len-i-1];
            result = max(result,max(left,right));
        }

        return result;
    }
};