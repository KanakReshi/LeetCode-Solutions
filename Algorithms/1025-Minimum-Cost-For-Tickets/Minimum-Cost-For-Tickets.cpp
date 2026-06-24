class Solution {
public:
    int create(vector<int>& days , vector<int>& costs , int k,int n,vector<int>&dp){
        if(k>=n)return 0;
        if(dp[k] != -1)return dp[k];
        int day = costs[0] + create(days,costs,k+1,n,dp);
        int i;
        for(i = k; i<n && days[i] < days[k] + 7;i++);
        int week = costs[1] + create(days,costs,i,n,dp);
        for(i = k; i<n && days[i] < days[k] + 30;i++);
        int month = costs[2] + create(days,costs,i,n,dp);
        return dp[k] = min(day,min(week,month));
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        vector<int>dp(n+1,-1);
        return create(days,costs,0,n,dp);
    }
};