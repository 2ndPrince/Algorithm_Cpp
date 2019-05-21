// https://leetcode.com/problems/last-stone-weight/

// My Solution

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        int N = stones.size();
        while(stones.size()!=1){
            sort(stones.begin(), stones.end());
            N = stones.size();
            int temp = stones[N-1] - stones[N-2];
            vector<int> container;
            for(int i=0;i<N-2;i++){
                container.push_back(stones[i]);
            }
            container.push_back(temp);
            stones = container;
        }
        
        return stones[0];
    }
};
// 1. Sort the array to pick the two heaviest
// 2. Renew the array with the result from (1)
// 3. Repeat (1) and (2) until only one element on the array left

// Neal_Wu's

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        while (stones.size() > 1) {
            sort(stones.begin(), stones.end());
            int n = stones.size();
            int a = stones[n - 2], b = stones[n - 1];
            stones.resize(n - 2);
            stones.push_back(b - a);
        }

        return stones.back();
    }
};
