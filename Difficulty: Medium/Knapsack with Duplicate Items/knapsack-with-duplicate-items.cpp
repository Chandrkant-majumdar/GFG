//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int find(int i,int n,int val[], int wt[],vector<vector<int>>&dp){
        if(i == 0) {
            return (n / wt[0]) * val[0];
        }
        if(n==0)return 0;
        if(dp[i][n]!=-1)return dp[i][n];
        int nottake=find(i-1,n,val,wt,dp);
        int take=0;
        if(wt[i]<=n){
            take=val[i]+find(i,n-wt[i],val,wt,dp);
        }
        return dp[i][n]=max(take,nottake);
        
    }
    int knapSack(int N, int W, int val[], int wt[])
    {
        // code here
        vector<vector<int>> dp(N, vector<int>(W + 1, -1));
        int ans=find(N-1,W,val,wt,dp);
        // if(ans==-1e9){
        //     return 0;
        // }
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, W;
        cin>>N>>W;
        int val[N], wt[N];
        for(int i = 0;i < N;i++)
            cin>>val[i];
        for(int i = 0;i < N;i++)
            cin>>wt[i];
        
        Solution ob;
        cout<<ob.knapSack(N, W, val, wt)<<endl;
    }
    return 0;
}
// } Driver Code Ends