//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:
	int mod=1e9+7;
	int f(int i,int sum,int arr[],vector<vector<int>>&dp){
        // if(sum==arr[i]) return 1;
        // if(i==0){
        if(i==0){
            if(sum==0 && arr[i]==0) return 2;
            if(sum==0 || sum==arr[i]) return 1;
            return 0;
        }
       
           
        //   if(sum==0 && arr[i]==sum) return 2;
           
        //   return arr[i]==sum;
            
        
        
        if(dp[i][sum]!=-1) return dp[i][sum];
        
        int tk=(sum>=arr[i])?f(i-1,sum-arr[i],arr,dp):0;
        int nt=f(i-1,sum,arr,dp);
        
        return dp[i][sum]=(tk+nt)%(mod);
    }
	int perfectSum(int arr[], int n, int sum)
	{
        // Your code goes here
        //  int n=arr.size();
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
	     
    
cout << "~" << "\n";
}
    return 0;
}

// } Driver Code Ends