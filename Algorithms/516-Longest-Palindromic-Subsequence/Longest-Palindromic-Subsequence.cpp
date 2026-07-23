class Solution {
    int create(string &s , int i , int j,vector<vector<int>> &dp){
        if(i > j)return 0;
        if(i==j)return 1;
        if(dp[i][j] != -1)return dp[i][j];
        if(s[i] == s[j])return 2 + create(s,i+1,j-1,dp);
        int left_side = create(s,i,j-1,dp);
        int right_side = create(s,i+1,j,dp);
        return dp[i][j] = max(left_side,right_side);
    }
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        return create(s,0,n-1,dp);
    }
};