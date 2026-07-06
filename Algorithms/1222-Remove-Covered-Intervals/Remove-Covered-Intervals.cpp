class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](const auto& a, const auto& b) {
            if (a[0] == b[0])
                return a[1] > b[1];
            return a[0] < b[0];
        });
        int count = 0;
        vector<bool> mark(intervals.size(), false);
        for(int i = 0; i < intervals.size() - 1; i++) {
            for(int j = i + 1; j < intervals.size(); j++) {
                if(intervals[i][0] <= intervals[j][0] &&
                    intervals[i][1] >= intervals[j][1] &&
                    !mark[j]) {
                        count++;
                        mark[j] = true;
                    }
            }
        }
        return intervals.size() - count;
    }
};