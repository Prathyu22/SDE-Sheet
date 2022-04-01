#https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

class Solution {
    public int maxProfit(int[] prices) {
        int max_suffix = 0;
        int max_profit = 0;
        int n = prices.length;
        
        //Suffix Algorithm
        for(int i=n-1; i>-1; i--)
        {
            max_suffix = Math.max(max_suffix, prices[i]);
            max_profit = Math.max(max_profit, max_suffix-prices[i]);
        }
        return max_profit;
    }
}