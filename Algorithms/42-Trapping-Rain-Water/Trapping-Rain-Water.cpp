class Solution {
public:
    int trap(vector<int>& height) {
        int len = height.size();
        int result=0,l=0,r=len-1;
        int leftmax=0,rightmax=0;
        while(l<r){
            leftmax=max(leftmax,height[l]);
            rightmax=max(rightmax,height[r]);
            if(leftmax<rightmax){
                result += leftmax - height[l];
                l++;
            }
            else{
                result += rightmax - height[r];
                r--;
            }
        }
        return result;
    }
};