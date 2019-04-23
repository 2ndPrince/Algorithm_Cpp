// 1029. Two City Scheduling
// https://leetcode.com/contest/weekly-contest-133/problems/two-city-scheduling/

class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        int res = 0;
        sort(costs.begin(), costs.end(), [](vector<int> &a, vector<int> &b){ return a[0] - a[1] < b[0] - b[1]; });
        int cnt = 0;
        for (vector<int> &cost : costs) {
            if (cnt < costs.size() / 2) {
                res += cost[0];
            } else {
                res += cost[1];
            }
            cnt++;
        }
        return res;
    }
};


// My solution

class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        int ret = 0;
        sort(costs.begin(), costs.end(), cmp);
        for(int k=0;k<costs.size()/2;k++) ret += costs[k][0];
        for(int k=costs.size()/2;k<costs.size();k++) ret += costs[k][1];
       return ret;
    }
    
    static bool cmp(vector<int>& A, vector<int>& B){
        return (A[0]-A[1]) < (B[0]-B[1]);
    }
};

// costs[i][0] - costs[i][1] if minus -> should go to city B. Costs[i][1]
