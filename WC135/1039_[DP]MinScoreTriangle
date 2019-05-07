// https://leetcode.com/contest/weekly-contest-135/problems/minimum-score-triangulation-of-polygon/

// Java solution

	class Solution {
	    public int minScoreTriangulation(int[] a) {
	        int n = a.length;
	        int[][] dp = new int[n][n];
	        for(int len = 2;len < n;len++){ 
	        	for(int i = 0;i+len < n;i++){	
	        		int j = i+len;
	        		dp[i][j] = Integer.MAX_VALUE;
	        		for(int k = i+1;k < j;k++){
	        			dp[i][j] = Math.min(dp[i][j], dp[i][k] + dp[k][j] + a[i]*a[j]*a[k]);
	        		}
	        	}
	        }
	        return dp[0][n-1];
	    }
	}	

// My solution after solution

class Solution {
public:
    int minScoreTriangulation(vector<int>& A) {
        int n = A.size();
        vector<vector<int>> dp(n, vector<int>(n,0));
        for(int len=2; len<=n; len++){
            for(int i=0;i+len<n;i++){
                int j = i + len;
                dp[i][j] = INT_MAX;
                for(int k=i+1;k<j;k++){
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j] + A[i]*A[j]*A[k]);
                }
            }
        }
        return dp[0][n-1];
    }
};

// 1. Loop twice and find the right i and j so that (i*j)*others are the minimum
