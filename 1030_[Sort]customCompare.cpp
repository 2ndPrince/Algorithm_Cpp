// https://leetcode.com/contest/weekly-contest-133/problems/matrix-cells-in-distance-order/

int bx;
int by;
int dist(vector<int> &a) {
	return abs(a[0] - bx) + abs(a[1] - by);
}
bool cmp(vector<int> &a, vector<int> &b) {
	return dist(a) < dist(b);
}
class Solution {
public:
    vector<vector<int> > v;

vector<vector<int>> allCellsDistOrder(int R, int C, int r0, int c0) {
	
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			vector<int> ret;
			ret.push_back(i);
			ret.push_back(j);
			v.push_back(ret);
		}
	}
	bx = r0;
	by = c0;
	sort(v.begin(), v.end(), cmp);
	return v;
}
};
