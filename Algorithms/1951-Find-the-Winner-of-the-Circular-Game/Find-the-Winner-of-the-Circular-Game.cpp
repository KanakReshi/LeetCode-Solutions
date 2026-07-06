class Solution {
public:
    int findTheWinner(int n, int k) {
        vector<int>nums(n+1);
        for(int i = 0 ; i < n+1 ;i++){
            nums[i] = i;
        }
        int i = 1;
        int count = 1;
        while(nums.size() > 2){
            if(i==nums.size())i = 1;
            if(count == k){
                nums.erase(nums.begin() + i);
                // i--;
                count = 1;
            }
            else{
                count++;
                i++;
            }
        }
        return nums[1];
    }
};