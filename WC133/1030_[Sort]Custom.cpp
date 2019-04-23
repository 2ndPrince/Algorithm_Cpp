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


// My solution
int ro = 0; // These have to be placed outside the class. Otherwise, error. I am not sure why.
int co = 0;

class Solution {
public:
    vector<vector<int>> allCellsDistOrder(int R, int C, int r0, int c0) {
        ro = r0;
        co = c0;
        vector<vector<int>> map;
        for(int i=0;i<R;i++){
            for(int j=0;j<C;j++){
                map.push_back({i,j});
            }
        }
        sort(map.begin(), map.end(), customCompare);        
        return map;
    }
    
    static bool customCompare(vector<int>& p1, vector<int>& p2){
        int d1 = abs(p1[0]-ro) + abs(p1[1]-co);
        int d2 = abs(p2[0]-ro) + abs(p2[1]-co);
        return d1 < d2;
    }
};

// 1. create a map of coordinates
// 2. define a custom sort function for distance
// 3. sort the map with the custom sort function
// 4. return the map data

// without static: it gave error.
// https://stackoverflow.com/questions/29286863/invalid-use-of-non-static-member-function
