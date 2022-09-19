//https://leetcode.com/problems/permutations/

/*
Print All Permutations of a String/Array
Problem Statement: Given an array arr of distinct integers, print all permutations of String/Array.

Examples:

Example 1: 

Input: arr = [1, 2, 3]

Output: 
[
  [1, 2, 3],
  [1, 3, 2],
  [2, 1, 3],
  [2, 3, 1],
  [3, 1, 2],
  [3, 2, 1]
]

Explanation: Given an array, return all the possible permutations.

Example 2:

Input: arr = [0, 1]

Output:
[
  [0, 1],
  [1, 0]
]

Explanation: Given an array, return all the possible permutations.
*/

class Solution {
private:
    /*------ TC = n! * n and SC = O(n) + O(n) ------------ */
    /*
    void func(vector<int>& nums, vector<int>& ds, vector<vector<int>>& ans, int map[])
    {
        if(ds.size() == nums.size())
        {
            ans.push_back(ds);
            return;
        }
        for(int i=0; i<nums.size(); i++)
        {
            if(!map[i])
            {
                ds.push_back(nums[i]);
                map[i] = 1;
                func(nums, ds, ans, map);
                map[i] = 0;
                ds.pop_back();
            }
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> ds;
        vector<vector<int>> ans;
        int map[nums.size()];
        for(int i=0; i<nums.size(); i++)
        {
            map[i] = 0;
        }
        func(nums, ds, ans, map);
        return ans;
    } */
private:
/* ---------- TC = n! * n and SC = O(1) -------------- */
    void func(int ind, vector<int>& nums, vector<vector<int>>& ans)
    {
        if(ind == nums.size())
        {
            ans.push_back(nums);
            return;
        }
        
        for(int i=ind; i<nums.size(); i++)
        {
            swap(nums[ind],nums[i]);
            func(ind+1, nums, ans);
            swap(nums[ind], nums[i]);
        }
    }
    
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        func(0, nums, ans);
        return ans;
    }
    
};