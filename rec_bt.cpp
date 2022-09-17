//https://www.codingninjas.com/codestudio/problems/subset-sum_3843086?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website

/*
Subset Sum : Sum of all Subsets
Problem Statement: Given an array print all the sum of the subset generated from it, in the increasing order.

Examples:

Example 1:

Input: N = 3, arr[] = {5,2,1}

Output: 0,1,2,3,5,6,7,8

Explanation: We have to find all the subset’s sum and print them.in this case the generated subsets are [ [], [1], [2], [2,1], [5], [5,1], [5,2]. [5,2,1],so the sums we get will be  0,1,2,3,5,6,7,8


Input: N=3,arr[]= {3,1,2}

Output: 0,1,2,3,3,4,5,6

Explanation: We have to find all the subset’s sum and print them.in this case the generated subsets are [ [], [1], [2], [2,1], [3], [3,1], [3,2]. [3,2,1],so the sums we get will be  0,1,2,3,3,4,5,6
*/

#include <bits/stdc++.h> 

void func(int i, vector<int>& num, int n, vector<int>& ans, int sum){
    if(i >= n) {
        ans.push_back(sum);
        return;
    }
    //pick
    func(i+1, num, n, ans, sum+num[i]);
    //not pick
    func(i+1, num, n, ans, sum);
}

vector<int> subsetSum(vector<int> &num)
{
    // Write your code here.
    vector<int> ans;
    int n = num.size();
    // func(index, num, num.size(), ans, sum)
    func(0, num, n, ans, 0);
    sort(ans.begin(), ans.end());
    return ans;
}