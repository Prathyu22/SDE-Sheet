//https://practice.geeksforgeeks.org/problems/longest-palindrome-in-a-string3411/1

//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    string reverse(string s, int i, int j)
    {
        int ii =i;
        int jj = j;
        while(i<=j)
        {
            swap(s[i++],s[j--]);
        }
        return s.substr(ii,jj-ii+1);
    }
  
    string longestPalin (string S) {
        // code here
        string s2 = "";
        int max_length = 1;
        int i_index;
        int j_index;
        for(int i=0; i<S.size(); i++)
        {
            for(int j=i; j<S.size(); j++)
            {
                if(reverse(S,i,j) == S.substr(i,j-i+1))
                {
                    if(max_length < j-i+1)
                    {
                        max_length = j-i+1;
                         i_index = i;
                         j_index = j;
                    }
                }
            }
        }
        
        if(max_length == 1)
        {
            s2 = S[0];
            return s2;
        }
        return S.substr(i_index,max_length);
    }
};

//{ Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        string S; cin >> S;
        
        Solution ob;
        cout << ob.longestPalin (S) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends