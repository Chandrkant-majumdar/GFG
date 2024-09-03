//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
		

	public:
	int f(int i,int j,string &s1,string &s2,vector<vector<int>>&dp){
	    
	   // if(i<0 && j<0) return 0;
	    
	    if(i<0) return j+1;
	    if(j<0) return i+1;
	    
	    if(dp[i][j]!=-1) return dp[i][j];
	   // if(i==0 && j==0){
	   //     if(s1[i]==s2[j]) return 1;
	   //     return 0;
	   // }
	    int ans=INT_MAX;
	    if(s1[i]==s2[j]){
	        return dp[i][j]=f(i-1,j-1,s1,s2,dp);
	    }
	    
	    
	    return dp[i][j]=min(1+f(i,j-1,s1,s2,dp),1+f(i-1,j,s1,s2,dp));
	}
	int minOperations(string str1, string str2) 
	{ 
	    // Your code goes here
	    int n=str1.size(),m=str2.size();
	    vector<vector<int>>dp(n,vector<int>(m,-1));
	    return f(n-1,m-1,str1,str2,dp);
	    
	} 
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        string s1, s2;
        cin >> s1 >> s2;

	    Solution ob;
	    cout << ob.minOperations(s1, s2) << "\n";
	     
    }
    return 0;
}


// } Driver Code Ends