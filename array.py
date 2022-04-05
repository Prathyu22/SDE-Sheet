#https://practice.geeksforgeeks.org/problems/trapping-rain-water-1587115621/1#

        #Code here
        # initialize output
        result = 0
     
        # maximum element on left and right
        left_max = 0
        right_max = 0
     
        # indices to traverse the array
        lo = 0
        hi = n-1
     
        while(lo <= hi): 
            if(arr[lo] < arr[hi]):
                if(arr[lo] > left_max):
                    # update max in left
                    left_max = arr[lo]
                else:
                    # water on curr element = max - curr
                    result += left_max - arr[lo]
                lo+= 1
        
            else:
                if(arr[hi] > right_max):
                    # update right maximum
                    right_max = arr[hi]
                else:
                    result += right_max - arr[hi]
                hi-= 1
        
        return result

#{ 
#  Driver Code Starts
#Initial Template for Python 3

import math



def main():
        T=int(input())
        while(T>0):
            
            n=int(input())
            
            arr=[int(x) for x in input().strip().split()]
            obj = Solution()
            print(obj.trappingWater(arr,n))
            
            
            T-=1


if __name__ == "__main__":
    main()



# } Driver Code Ends