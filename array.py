#https://practice.geeksforgeeks.org/problems/find-duplicates-in-an-array/1#

    def duplicates(self, arr, n): 
        # code here
        for i in range(n):
            arr[arr[i] % n] = arr[arr[i] % n] + n
        
        nums = []
        flag = False
        
        for i in range(n):
            if(arr[i] >= n*2):
                nums.append(i)
                flag = True
                
        if flag == False:
            nums.append(-1)
                
        return nums 
        
        
#{ 
#  Driver Code Starts
if(__name__=='__main__'):
    t = int(input())
    for i in range(t):
        n = int(input())
        arr = list(map(int, input().strip().split()))
        res = Solution().duplicates(arr, n)
        for i in res:
            print(i,end=" ")
        print()



# } Driver Code Ends