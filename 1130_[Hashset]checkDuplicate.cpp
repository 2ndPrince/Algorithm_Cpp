// The hash set is one of the implementations of a set which is a data structure to store no repeated values. 
// https://leetcode.com/explore/learn/card/hash-table/183/combination-with-other-algorithms/1130/

/*
Given an array of integers, find if the array contains any duplicates.
Your function should return true if any value appears at least twice in the array, 
and it should return false if every element is distinct.

Example 1:
Input: [1,2,3,1]
Output: true
*/

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> s;
        for(int i=0;i<nums.size();i++){
            if(s.find(nums[i])==s.end()){
                s.insert(nums[i]);
            }else{
                return true;
            }         
        }
        return false;
    }
};
