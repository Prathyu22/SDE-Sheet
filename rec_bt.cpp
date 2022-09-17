//https://www.codingninjas.com/codestudio/problems/unique-subsets_3625236?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=1

/*
Subset – II | Print all the Unique Subsets
Problem Statement: Given an array of integers that may contain duplicates the task is to return all possible subsets. Return only unique subsets and they can be in any order.

Examples:

Example 1:

Input: array[] = [1,2,2]

Output: [ [ ],[1],[1,2],[1,2,2],[2],[2,2] ]

Explanation: We can have subsets ranging from  length 0 to 3. which are listed above. Also the subset [1,2] appears twice but is printed only once as we require only unique subsets.

Input: array[] = [1]

Output: [ [ ], [1] ]

Explanation: Only two unique subsets are available
*/

#include <bits/stdc++.h> 

void func(int ind, vector<int>& arr, vector<int>& ds, vector<vector<int>>& ans)
{
    ans.push_back(ds);
    for(int i=ind; i<arr.size(); i++){
        if( (i != ind) && (arr[i] == arr[i-1]) ) continue;
        ds.push_back(arr[i]);
        func(i+1, arr, ds, ans);
        ds.pop_back();
    }
}

vector<vector<int>> uniqueSubsets(int n, vector<int> &arr)
{
    // Write your code here.
    vector<vector<int>> ans;
    vector<int> ds;
    sort(arr.begin(), arr.end());
    func(0, arr, ds, ans);
    return ans;
}