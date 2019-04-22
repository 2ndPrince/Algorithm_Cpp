// Matrix Cells in Distance Order
// https://leetcode.com/contest/weekly-contest-133/problems/matrix-cells-in-distance-order/

int r, c;
bool cmp(const vector<int>& p1, const vector<int>& p2) {
    int d1 = abs(p1[0] - r) + abs(p1[1] - c);
    int d2 = abs(p2[0] - r) + abs(p2[1] - c);
    return d1 < d2;
}
class Solution {
public:
    
    
    vector<vector<int>> allCellsDistOrder(int R, int C, int r0, int c0) {
        r = r0;
        c = c0;
        vector<vector<int>> res;
        for(int i=0; i<R; i++) {
            for(int j=0; j<C; j++) {
                res.push_back({i, j});
            }
        }
        sort(res.begin(), res.end(), cmp);
        
        return res;
        
    }
};
