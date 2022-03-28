//https://practice.geeksforgeeks.org/problems/sort-an-array-of-0s-1s-and-2s4231/1#

#include<bits/stdc++.h>
using namespace std;



 // } Driver Code Ends
class Solution
{
    public:
    void sort012(int a[], int n)
    {
        // code here
        int l = 0;
        int mid = 0;
        int h = n-1;
        int temp = 0;
        
        while(mid<=h)
        {
            if(a[mid]==0)
            {
                temp = a[mid];
                a[mid] = a[l];
                a[l] = temp;
                mid ++;
                l ++;
            }
            else if(a[mid]==1)
            {
                mid ++;
            }
            else if(a[mid]==2)
            {
                temp = a[mid];
                a[mid] = a[h];
                a[h] = temp;
                h --;
            }
        }

    }
    
};

// { Driver Code Starts.
int main() {

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >>n;
        int a[n];
        for(int i=0;i<n;i++){
            cin >> a[i];
        }

        Solution ob;
        ob.sort012(a, n);

        for(int i=0;i<n;i++){
            cout << a[i]  << " ";
        }

        cout << endl;
        
        
    }
    return 0;
}

  // } Driver Code Ends