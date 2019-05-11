// https://leetcode.com/problems/jump-game/

// My solution

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int N = nums.size();
        vector<bool> DP(N, false);
        DP[0] = true;
        for(int i=1;i<=N;i++){
            for(int k=1; k <= i; k++){
                DP[i] = (DP[i-k] && nums[i-k] >= k) ? true : false;
                if(DP[i]) k = i+1;
            }
        }
        return DP[N-1];
    }
};
