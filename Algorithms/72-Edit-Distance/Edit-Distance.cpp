class Solution {
public:
    int create(string &word1 , string &word2 , int i , int j,vector<vector<int>> &dp){
        if(i == word1.size())return word2.size() - j;
        if(j == word2.size())return word1.size() - i;
        if(dp[i][j] != -1)return dp[i][j];
        if(word1[i] == word2[j]){
            return create(word1,word2,i+1,j+1,dp);
        }
            int insert = create(word1,word2,i,j+1,dp);
            int del = create(word1,word2,i+1,j,dp);
            int replace = create(word1,word2,i+1,j+1,dp);
            return dp[i][j] = 1 + min(insert,min(del,replace));
    }

    int minDistance(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();
        vector<vector<int>>dp(m , vector<int>(n,-1));
        return create(word1,word2,0,0,dp); 
    }
};