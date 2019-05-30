// 1054. Distant Barcodes
// Solution from discussion
// https://leetcode.com/problems/distant-barcodes/discuss/299371/C%2B%2B-with-picture-O(N)

/*
Solution
1. Count occurrences of each barcode using a hash map
2. Use a set to sort barcodes by their number of occurrences
3. Starting from most frequent, fill even positions with barcodes
4. Then fill odd positions with remaining barcodes
*/

vector<int> rearrangeBarcodes(vector<int>& b, int pos = 0) {
  unordered_map<int, int> m;
  set<pair<int, int>> s;
  for (auto n : b) ++m[n];
  for (auto it = begin(m); it != end(m); ++it) s.insert({ it->second, it->first });
  for (auto it = s.rbegin(); it != s.rend(); ++it) {
    for (auto cnt = 0; cnt < it->first; ++cnt, pos += 2) {
      if (pos >= b.size()) pos = 1;
      b[pos] = it->second;
    }
  }
  return b;
}
