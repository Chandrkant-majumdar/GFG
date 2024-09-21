//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
  public:
     int f(int i,int N,int p[],vector<vector<int>>&dp){
         
         if(i==0){
             return N*p[0];
         }
         if(dp[i][N]!=-1) return dp[i][N];
         
         int len=i+1;
         int tk=(N>=len)?p[i]+f(i,N-len,p,dp):0;
         int nt=f(i-1,N,p,dp);
         return dp[i][N]= max(tk,nt);
     }
    int cutRod(int p[], int n) {
        //code here
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return f(n-1,n,p,dp);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) 
            cin >> a[i];
            
        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends