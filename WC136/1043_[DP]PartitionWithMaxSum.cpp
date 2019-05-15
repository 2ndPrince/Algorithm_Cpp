// 1043
// https://leetcode.com/contest/weekly-contest-136/problems/partition-array-for-maximum-sum/
// Solution from neal_wu

class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& A, int K) {
        int N = A.size();
        vector<int> dp(N + 1, 0);

        for (int i = 1; i <= N; i++) {
            int most = 0;

            for (int j = i - 1; j >= max(i - K, 0); j--) {
                most = max(most, A[j]);
                dp[i] = max(dp[i], dp[j] + (i - j) * most);
            }
        }

        return dp[N];
    }
};
