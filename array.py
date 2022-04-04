#https://practice.geeksforgeeks.org/problems/maximum-product-subarray3604/1#

class Solution:

    # Function to find maximum
    # product subarray
    def maxProduct(self,arr, n):
        # code here
        max_val = arr[0]
        min_val = arr[0]
        max_product = arr[0]
        
        for i in range(1,n,1):
            #if the present element is "-ve", the max and min values are swapped.
            if(arr[i] < 0):
                temp = max_val
                max_val = min_val
                min_val = temp
            
            max_val = max(arr[i], max_val*arr[i])
            min_val = min(arr[i], min_val*arr[i])
            
            max_product = max(max_product, max_val)
            
        return max_product

#{ 
#  Driver Code Starts
#Initial Template for Python 3



if __name__ == '__main__':
    tc = int(input())
    while tc > 0:
        n = int(input())
        arr = list(map(int, input().strip().split()))
        ob = Solution()
        ans = ob.maxProduct(arr, n)
        print(ans)
        tc -= 1

# } Driver Code Ends