class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(),intervals.end(),[](vector<int>&a,vector<int>&b){
            return a[1]<b[1];
        });
        int start1 = intervals[0][0];
        int end1 = intervals[0][1];
        int remove = 0;
        for(int i = 1 ;i < n;i++){
            int start2 = intervals[i][0];
            int end2 = intervals[i][1];
            if(start2 < end1){
                remove++;
            }
            else{
                start1 = intervals[i][0];
                end1 = intervals[i][1];
            }
        }
        return remove;
    }
};