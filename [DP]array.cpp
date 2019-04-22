// 1031. Maximum Sum of Two Non-Overlapping Subarrays
// https://leetcode.com/problems/maximum-sum-of-two-non-overlapping-subarrays/

/*
Given an array A of non-negative integers, return the maximum sum of elements in two non-overlapping (contiguous) subarrays, which have lengths L and M.  (For clarification, the L-length subarray could occur before or after the M-length subarray.)

Formally, return the largest V for which V = (A[i] + A[i+1] + ... + A[i+L-1]) + (A[j] + A[j+1] + ... + A[j+M-1]) and either:

0 <= i < i + L - 1 < j < j + M - 1 < A.length, or
0 <= j < j + M - 1 < i < i + L - 1 < A.length.
*/

class Solution {
public:
    int maxSumTwoNoOverlap(vector<int>& A, int L, int M) {
        int N=A.size();
        vector<int> sums(N+1,0);
        for(int i=0;i<N;i++) sums[i+1]=A[i]+sums[i];
        int r=-1;
        for(int i=0;i+L<=N;i++){
            for(int j=i+L;j+M<=N;j++){
                r=max(r,sums[i+L]-sums[i]+sums[j+M]-sums[j]);
            }
            for(int j=0;j+M<=i;j++)
                r=max(r,sums[i+L]-sums[i]+sums[j+M]-sums[j]);
        }
        return r;
    }
};
