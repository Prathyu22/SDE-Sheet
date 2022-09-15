//https://leetcode.com/problems/climbing-stairs/

/*
You are climbing a staircase. It takes n steps to reach the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

Example 1:

Input: n = 2
Output: 2
Explanation: There are two ways to climb to the top.
1. 1 step + 1 step
2. 2 steps


Example 2:

Input: n = 3
Output: 3
Explanation: There are three ways to climb to the top.
1. 1 step + 1 step + 1 step
2. 1 step + 2 steps
3. 2 steps + 1 step
 

Constraints:
1 <= n <= 45 

*/

class Solution {
public:
    int climbStairs(int n) {
/*-------------Recursion (TLE).-----------------*/
        /*int mk(int n)
        {
           if(n<0) return 0;
           if(n==0) return 1;
           return mk(n-1)+mk(n-2); 
        } 
        int climbStairs(int n) {
           return mk(n);
        } */
        
/*--------------memoization of recursion solution.-----------*/
        /*int mk(int n,vector<int> &memo)
        {     
           if(n<0) return 0;
           if(memo[n]!=-1) return memo[n];
           if(n==0) return 1;
           return memo[n]=mk(n-1,memo)+mk(n-2,memo);
        }
     
        int climbStairs(int n) {
           vector<int> memo(n+1,-1);
           return mk(n,memo);
        } */
        
/*----------------memoization to DP. -----------------*/
        if(n < 1) return 0;
        if(n == 1) return 1;
        int dp[100];
        dp[0] = 1;
        dp[1] = 2;
        for(int i=2; i<n; i++){
            dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[n-1];
    }
};