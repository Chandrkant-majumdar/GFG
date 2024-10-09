//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// Function to find square root
// x: element to find square root
class Solution {
  public:
    long long int floorSqrt(long long int n) {
        // Your code goes here
        // if(n==1) return 1;
        long long l=1,h=n,t;
        while(l<=h){
            long long m=(l+h)/2;
            long long ans=m*m;
            if(ans==n) return m;
            if(ans<n){
               t=m;
                l=m+1;
                
            }else{
                 
                h=m-1;
            }
        }
        return t;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;
        Solution obj;
        cout << obj.floorSqrt(n) << endl;
    }
    return 0;
}

// } Driver Code Ends