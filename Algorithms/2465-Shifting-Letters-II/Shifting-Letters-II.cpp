class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = s.size();
        vector<long long> diff(n+1,0);
        for(int i = 0 ; i < shifts.size() ; i++){
            int start = shifts[i][0];
            int end = shifts[i][1];
            int direction = shifts[i][2]==1?1:-1;
            diff[start] += direction;
            diff[end + 1] -= direction;
        }
        int steps = 0;
        for(int i = 0 ;i < n ; i++){
            steps += diff[i];
            int shifts = ((steps % 26)+26)%26;
            s[i] = 'a' + (s[i] - 'a' + shifts)%26;
        }
        return s;
    }
};