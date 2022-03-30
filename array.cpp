//https://practice.geeksforgeeks.org/problems/next-permutation5226/1#

// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<int> nextPermutation(int N, vector<int> arr){
        // code here
        
        if(N==1)
           return arr;
           
        int i=1;
        int last_peak_idx = -1;
        
        while(i<N)
        {
            if(arr[i] > arr[i-1])
              last_peak_idx = i;
            i += 1;
        }
        
        if(last_peak_idx == -1)
        {
            sort(arr.begin(), arr.end());
            return arr;
        }
        
        
        int last_peak = arr[last_peak_idx];
        int index = last_peak_idx;
        int idx = 0;
        
        if((index == N-1) && (arr[index] > arr[index-1]))
        {
            swap(arr[index], arr[index-1]);
            return arr;
        }
        
        
        for(i=index+1; i<N; ++i)
        {
            if(arr[i] > arr[index-1] and arr[i] < last_peak)
            {
                idx = i;
            }
        }
        
        swap(arr[index-1], arr[idx]);
        
        sort(arr.begin()+index, arr.end());
        
        return arr;

    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        vector<int> ans = ob.nextPermutation(N, arr);
        for(int u: ans)
            cout<<u<<" ";
        cout<<"\n";
    }
    return 0;
}  // } Driver Code Ends