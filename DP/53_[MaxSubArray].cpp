// https://leetcode.com/problems/maximum-subarray/

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxium = nums[0];
        int sum = 0;
        for (int i=0;i<nums.size();i++){
            sum+=nums[i];
            maxium = max(sum,maxium);
            sum = max(0,sum);
        }
        return maxium;
    }
};
