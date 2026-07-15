class Solution {
    int min_out(int a,int b){
        return(a<b)?a:b;
    }
    int gcd_out(int a,int b){
        int min = min_out(a,b);
        for(int i = min;i>=1;i--){
            if(a%i==0 && b%i==0)return i;
        }
        return 1;
    }
public:
    int gcdOfOddEvenSums(int n) {
        if(n==0)return 0;
        if(n==1)return 1;
        int sum_odd = n*n;
        int sum_even = n*(n+1);
        return gcd_out(sum_odd,sum_even);
    }
};