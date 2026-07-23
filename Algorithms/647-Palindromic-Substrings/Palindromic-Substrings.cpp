class Solution {
public:
    bool ispalindrome(string &s , int start , int end){
        // if(start==end)return true;
        int i = start;
        int j = end;
        while(start < end){
            if(s[start] != s[end])return false;
            start++;
            end--;
        }
        return true;
    }
    int countSubstrings(string s) {
       int n = s.size();
       int result = 0;
       for(int i = 0 ; i < n ;i++){
        for(int j = i ; j < n;j++){
            if(ispalindrome(s,i,j))result++;
        }
       }
       return result; 
    }
};