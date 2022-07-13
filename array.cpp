//https://practice.geeksforgeeks.org/problems/inversion-of-array-1587115620/1#

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
  public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    
    long long merge(vector<long long>&nums, int low,int mid,int high)
    {
        long long inv_count=0, k=0;
        int l = low, r = mid+1, size = high-low+1;
        vector<long long>s(size);
        while(l <= mid and r <= high)
        {
            if(nums[l] <= nums[r]){
                s[k++] = nums[l++];
            }
            else
            {
                s[k++] = nums[r++];
                inv_count = inv_count + (mid-l+1); // only these changes
            }
        }
    
        while(l <= mid)
            s[k++] = nums[l++];
    
        while(r <= high)
            s[k++] = nums[r++];
    
        for(k = 0 ; k < size ; k++)
            nums[k+low] = s[k];
        return inv_count;
    }
    
    long long mergeSort(vector<long long>&nums,int low,int high)
    {
        long long inv_count = 0;
        if(low >= high) return 0;
        
        long long mid = low + (high-low)/2;
        inv_count += mergeSort(nums,low,mid);
        inv_count += mergeSort(nums,mid+1,high);
        inv_count += merge(nums,low,mid,high);
        return inv_count;
    }
    
    long long int inversionCount(long long arr[], long long N)
    {
        // Your Code Here
        vector<long long>nums;
        for(int i=0;i<N;i++) 
            nums.push_back(arr[i]);
            
        return mergeSort(nums, 0, N-1); 
    }
    
    

};

// { Driver Code Starts.

int main() {
    
    long long T;
    cin >> T;
    
    while(T--){
        long long N;
        cin >> N;
        
        long long A[N];
        for(long long i = 0;i<N;i++){
            cin >> A[i];
        }
        Solution obj;
        cout << obj.inversionCount(A,N) << endl;
    }
    
    return 0;
}
  // } Driver Code Ends