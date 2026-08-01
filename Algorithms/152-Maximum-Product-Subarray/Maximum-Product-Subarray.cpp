class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int maxelem = 1;
        int minelem = 1;
        int result = INT_MIN;
        for(int i = 0 ; i< n ;i++){
            int v1 = maxelem*nums[i];
            int v2 = nums[i];
            int v3 = minelem*nums[i];
            maxelem = max(v1,max(v2,v3));
            minelem = min(v1,min(v2,v3));
            result = max(result,maxelem);
        }
        return result;
    }
};