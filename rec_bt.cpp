//https://www.codingninjas.com/codestudio/problems/1112622?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=0

/*
Combination Sum II – Find all unique combinations
In this article we will solve the most asked interview question “Combination Sum II – Find all unique combinations”.

Problem Statement: Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sum to target. Each number in candidates may only be used once in the combination.

Note: The solution set must not contain duplicate combinations.

Examples:

Example 1:

Input: candidates = [10,1,2,7,6,1,5], target = 8

Output: 
[
[1,1,6],
[1,2,5],
[1,7],
[2,6]]


Explanation: These are the unique combinations whose sum is equal to target.
 
Example 2:

Input: candidates = [2,5,2,1,2], target = 5

Output: [[1,2,2],[5]]

Explanation: These are the unique combinations whose sum is equal to target.
*/

#include <bits/stdc++.h>
void func(int ind, vector<int>& arr, int n, int k, vector<vector<int>>& ans, vector<int>& ds, int sum)
{
    
        if(sum == k){
            ans.push_back(ds);
            return;
        }
    
    for(int i=ind; i<n; i++){
        if(i != ind && arr[i] == arr[i-1]) continue;
        if(arr[i] > k) break;
        ds.push_back(arr[i]);
        func(i+1, arr, n, k, ans, ds, sum+arr[i]);
        ds.pop_back();
        //func(i+1, arr, n, k, ans, ds, sum);
    }
}

vector<vector<int>> combinationSum2(vector<int> &arr, int n, int target)
{
	// Write your code here.
    vector<vector<int>> ans;
    vector<int> ds;
    sort(arr.begin(), arr.end());
    func(0, arr, n, target, ans, ds, 0);
    sort(ans.begin(), ans.end());
    return ans;
}
