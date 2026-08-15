class Solution {
public:
    int create(vector<int>& nums, int sum, int target, int i, int n,
               vector<vector<int>>& dp,int arr_sum) {
        if (i == n) {
            return (sum == target) ? 1 : 0;
        }
        if(dp[i][arr_sum + sum] != -1)return dp[i][arr_sum + sum]; 
        int elem = nums[i];
        int positive = create(nums, sum - elem, target, i + 1, n, dp,arr_sum);
        int negative = create(nums, sum + elem, target, i + 1, n, dp,arr_sum);
        return dp[i][arr_sum + sum] = positive + negative;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int arr_sum = 0;
        for(int it : nums){
            arr_sum += it;
        }
        vector<vector<int>> dp(n, vector<int>(2*(arr_sum) + 1, -1));
        return create(nums, 0, target, 0, n, dp, arr_sum);
    }
};