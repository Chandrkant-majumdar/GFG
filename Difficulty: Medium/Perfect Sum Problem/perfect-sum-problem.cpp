//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:
	int f(int i,int sum,int arr[],vector<vector<int>>&dp){
	   // if(i==0 && sum==0) return 2;
	   //if(sum==0) return 1;
	   int mod=1e9+7;
	    if(i==0){
	        if(sum==0 && arr[0]==0 ) return 2;
	        if(sum==0 || sum==arr[0]) return 1;
	        return 0;
	    } 
	    if(dp[i][sum]!=-1) return dp[i][sum];
	    int tk=(sum>=arr[i])?f(i-1,sum-arr[i],arr,dp):0;
	    int nt=f(i-1,sum,arr,dp);
	    return dp[i][sum]=(tk+nt)%mod;
	}
	int perfectSum(int arr[], int n, int sum)
	{
	    vector<vector<int>>dp(n,vector<int>(sum+1,-1));
        return f(n-1,sum,arr,dp);
	}
	  
};


//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, sum;

        cin >> n >> sum;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.perfectSum(a, n, sum) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends