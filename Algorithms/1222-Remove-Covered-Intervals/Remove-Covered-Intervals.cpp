class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        // sort(intervals.begin() , intervals.end());
        int len = intervals.size();
        vector<bool>check(len,true);
        for(int i = 0 ; i < len ; i++){
            for(int j = 0 ; j < len;j++){
                if(i==j)continue;
                if(intervals[j][0] >= intervals[i][0] && intervals[j][1] <= intervals[i][1]){
                    check[j] = false;
                }
            }
        }
        int result = 0;
        for(auto it : check){
            if(it)result++;
        }
        return result;
    }
};