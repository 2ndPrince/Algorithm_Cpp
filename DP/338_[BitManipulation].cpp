// 338. Counting Bits
// https://leetcode.com/problems/counting-bits/

// Solution from discussion board (JAVA)
// https://leetcode.com/problems/counting-bits/discuss/270693/Intermediate-processsolution-for-the-most-voted-solution-i.e.-no-simplificationtrick-hidden

class Solution {
    public int[] countBits(int num) {
        int[] res = new int[num + 1];
        res[0] = 0;
        
        for(int i = 1; i <= num; i++){
            if((i & 1) == 0){
                res[i] = res[i >> 1];
            }else{
                res[i] = res[i - 1] + 1;
            }
        }
        
        return res;
    }
}

// Below is my slow manual solution 

class Solution {
public:
    //int memo[10000000] = {-1};
    vector<int> ret;
    vector<int> countBits(int num) {
        for(int i=0;i<=num;i++){
            ret.push_back(cB(i));
        }
        return ret;
    }
    
    int cB(int num){
        //cout << num << " " << memo[num] << endl;
        if(num==0) return 0;
        if(num==1) return 1;
        //cout << "hi1";
        //if(memo[num]==-1) return memo[num];
        //cout << "hi2";
        int MSB = findMSB(num);
        int powered_MSB = pow(2,MSB);
        //cout << MSB << endl;
        //memo[num] = 1 + cB(num%powered_MSB);
        
        return 1 + cB(num%powered_MSB);
    }
    
    int findMSB(int a){
        int count = 0;
        while(a>1){
            a = a/2;
            count ++;
        }
        return count;
    }
    // 4 -> 2 -> 1 
    // 8 -> 4 -> 2 -> 1
    // 9 -> 4.5 -> 2.25 -> 1.25 
    // 15 -> 7.5 -> 3.75 -> 1.895 -> 0.9~
};



// 0: 0 (0)    : 0 = cB(0)
// 1: 1 (1)    : 1 = cB(1)
// 2: 10 (1)   : 1 + cB(0) = cB(2) = 1
// 3: 11 (2)   : 1 + cB(1) = cB(3) = 2
// 4: 100 (1)  : 1 + cB(0) = cB(4) = 1
// 5: 101 (2)  : 1 + cB(1)
// 6: 110 (2)  : 1 + cB(2)
// 7: 111 (3)  : 1 + cB(3)
// 8: 1000 (1) : 1 + cB(0)
// 9: 1001 (2) : 1 + cB(1)
//10: 1010 (2) : 1 + cB(2)
//11: 1011 (3) : 1 + cB(3)
//12: 1100 (2) : 1 + cB(4)
//13: 1101 (3) : 1 + cB(5)
//14: 1110 (3) : 1 + cB(6)
//15: 1111 (4) : 1 + cB(7)
//16: 10000 (1)


// cB[n] = 1 + cB[]
