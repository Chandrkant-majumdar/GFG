//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
  public:
    int f(int i,int rl,int p[],vector<vector<int>>&dp){
        if(rl==0) return 0;
        if(i==0) return rl*p[i];
        int len=i+1;
        if(dp[i][rl]!=-1) return dp[i][rl];
        int tk=(len<=rl)?p[i]+f(i,rl-len,p,dp):-1e9;
        int nt=f(i-1,rl,p,dp);
        return dp[i][rl]=max(tk,nt);
    }
    int cutRod(int p[], int n) {
        //code here
        vector<vector<int>>dp(n,vector<int>(n+1,-1));
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
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends