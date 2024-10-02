//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    int lenOfLongSubarr(int A[],  int n, int K) 
    { 
        // Complete the function
        int sum=0;
        map<int,int>m;
        int maxi=0;
        for(int i=0;i<n;i++){
            
            sum+=A[i];
            if(sum==K){
                maxi=max(maxi,i+1);
            }
            int rem=sum-K;
            if(m.find(rem)!=m.end()){
                
                maxi=max(maxi,i-m[rem]);
            }
            if(m.find(sum)==m.end()){
                m[sum]=i;
            }
                 
            }
            
            return maxi;
        }
       
    

};

//{ Driver Code Starts.

int main() {
	//code
	
	int t;cin>>t;
	while(t--)
	{
	    int n, k;
	    cin>> n >> k;
	    int a[n];
	    
	    for(int i=0;i<n;i++)
	        cin>>a[i];
	   Solution ob;
	   cout << ob.lenOfLongSubarr(a, n , k)<< endl;
	    
	}
	
	return 0;
}
// } Driver Code Ends