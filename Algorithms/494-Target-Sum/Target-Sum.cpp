class Solution {
public:
    int create(vector<int>& nums, int sum, int target, int i, int n,
               vector<vector<int>>& dp) {
        if (i == n) {
            return (sum == target) ? 1 : 0;
        }
        int elem = nums[i];
        int positive = create(nums, sum - elem, target, i + 1, n, dp);
        int negative = create(nums, sum + elem, target, i + 1, n, dp);
        return positive + negative;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(abs(target) + 1, -1));
        return create(nums, target, 0, 0, n, dp);
    }
};