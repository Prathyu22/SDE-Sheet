//https://www.codingninjas.com/codestudio/problems/759331?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=0

/*
Combination Sum – 1
Problem Statement: 

Given an array of distinct integers and a target, you have to return the list of all unique combinations where the chosen numbers sum to target. You may return the combinations in any order.

The same number may be chosen from the given array an unlimited number of times. Two combinations are unique if the frequency of at least one of the chosen numbers is different.

It is guaranteed that the number of unique combinations that sum up to target is less than 150 combinations for the given input.

Examples:

Example 1:

Input: array = [2,3,6,7], target = 7

Output: [[2,2,3],[7]]

Explanation: 2 and 3 are candidates, and 2 + 2 + 3 = 7. Note that 2 can be used multiple times.
             7 is a candidate, and 7 = 7.
             These are the only two combinations.


Example 2:

Input: array = [2], target = 1

Output: []

Explaination: No combination is possible.
*/

void func(int i, vector<int>& arr, vector<vector<int>>& ans, vector<int>& ds, int n, int k, int sum)
{
    if(i >= n){
        if(sum == k){
            ans.push_back(ds);
        }
        return;
    }
    //pick
    ds.push_back(arr[i]);
    func(i+1, arr, ans, ds, n, k, sum+arr[i]);
    ds.pop_back();
    func(i+1, arr, ans, ds, n, k, sum);
}

vector<vector<int>> findSubsetsThatSumToK(vector<int> arr, int n, int k)
{
    // Write your code here.
    vector<vector<int>> ans;
    vector<int> ds;
    
    func(0, arr, ans, ds, n, k, 0);
    return ans;
}