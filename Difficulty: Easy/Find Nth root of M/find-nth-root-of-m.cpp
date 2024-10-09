//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	long long f(long long b,long long e){
	    long long ans=1;
	    while(e>0){
	        if(e%2){
	            if (ans > LLONG_MAX / b) return LLONG_MAX;
	            ans*=b;
	            e--;
	        }else{
	            if (b > LLONG_MAX / b) return LLONG_MAX; 
	            b*=b;
	            e/=2;
	        }
	    }
	    return ans;
	}
	int NthRoot(int n, int m)
	{
	    // Code here.
	    
	    long long l=1,h=m;
	   //  cout<<f(3,2)<<endl;
	    while(l<=h){
	        long long mid=(l+h)/2;
	        long long  ans=f(mid,n);
	       
	        if(ans==m) return (int)mid;
	         if(ans<m){
	             l=mid+1;
	         }else{
	             h=mid-1;
	         }
	    }
	    return -1;
	}  
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		Solution ob;
		int ans = ob.NthRoot(n, m);
		cout << ans << "\n";
	}  
	return 0;
}
// } Driver Code Ends