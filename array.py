#https://practice.geeksforgeeks.org/problems/kadanes-algorithm-1587115620/1


class Solution:
    ##Complete this function
    #Function to find the sum of contiguous subarray with maximum sum.
    def maxSubArraySum(self,arr,N):
        ##Your code here
        ans = arr[0]
        prev_sum = 0
        cur_sum = 0
        
        for i in range(0,N):
            cur_sum = prev_sum + arr[i]
            ans = max(ans,cur_sum);
            prev_sum = max(0,cur_sum)
        return ans
#{ 
#  Driver Code Starts
#Initial Template for Python 3

import math

 
def main():
        T=int(input())
        while(T>0):
            
            n=int(input())
            
            arr=[int(x) for x in input().strip().split()]
            
            ob=Solution()
            
            print(ob.maxSubArraySum(arr,n))
            
            T-=1


if __name__ == "__main__":
    main()
# } Driver Code Ends