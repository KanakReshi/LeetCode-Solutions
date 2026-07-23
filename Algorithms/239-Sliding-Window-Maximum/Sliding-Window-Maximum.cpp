class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        map<int,int>mpp;
        int n = nums.size();
        for(int i = 0 ; i < k ;i++){
            mpp[nums[i]]++;
        }
        vector<int>max_subs;
        int max = mpp.rbegin()->first;
        max_subs.push_back(max);
        if(k==n)return max_subs;

        for(int i = k ; i < n ;i++){
            mpp[nums[i]]++;
            mpp[nums[i-k]]--;
            if(mpp[nums[i-k]] == 0)mpp.erase(nums[i-k]);
            max_subs.push_back(mpp.rbegin()->first);
        }
        return max_subs;
    }
};