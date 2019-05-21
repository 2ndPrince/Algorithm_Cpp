// 1047. Remove All Adjacent Duplicates In String

// My Solution

class Solution {
public:
    string myFunc(string S, int index){
        int N = S.size();
        string str;
        for(int i=0;i<N;i++){
            if(i!=index-1 && i!=index) str += S[i];
        }
        return str;
    }

    string removeDuplicates(string S) {
        bool stillDuplicate = true;
        while(stillDuplicate){
            for(int i=1;i<S.size();i++){
                if(S[i]==S[i-1]){
                    S = myFunc(S, i);
                }
            }
            stillDuplicate = false;
            for(int i=1;i<S.size();i++){
                if(S[i]==S[i-1]) stillDuplicate = true;
            }
        }
        return S;
    }
};

// Simplest C++ solution from beet


class Solution {
public:
  string removeDuplicates(string S) {
    string res;
    for(char c:S){
      if(res.empty()||res.back()!=c){
        res.push_back(c);
      }else{
        res.pop_back();
      }      
    }
    return res;
  }
};

// Solution from Neal_wu
lass Solution {
public:
    string removeDuplicates(string S) {
        while (true) {
            int n = S.size();
            vector<bool> keep(n, true);

            for (int i = 0; i + 1 < n; i++)
                if (keep[i] && keep[i + 1] && S[i] == S[i + 1]) {
                    keep[i] = keep[i + 1] = false;
                    int a = i - 1, b = i + 2;

                    while (true) {
                        while (a >= 0 && !keep[a])
                            a--;

                        while (b < n && !keep[b])
                            b++;

                        if (a >= 0 && b < n && keep[a] && keep[b] && S[a] == S[b]) {
                            keep[a] = keep[b] = false;
                        } else {
                            break;
                        }
                    }
                }
