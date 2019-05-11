// This is both DP and greedy

// https://leetcode.com/problems/video-stitching/

// My solution was based on https://leetcode.com/problems/video-stitching/discuss/270909/easy-python-DP-solution

class Solution {
public:
    int videoStitching(vector<vector<int>>& clips, int T) {
        int N = clips.size();
        vector<int> dp(T+1, N+1);
        dp[0] = 0;
        for(int i=0;i<=T; i++){
            for(vector<int>& clip: clips){
                if(i >= clip[0] && i <= clip[1]){
                    dp[i] = min(dp[i], dp[clip[0]] + 1);
                }
            }
        }
        if(dp[T] == N+1) return -1;
        else return dp[T];
    }
};
