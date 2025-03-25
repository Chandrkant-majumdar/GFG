//{ Driver Code Starts
// Initial template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function template for C++

class Solution {
  public:
   void helper(int n,int &ans){
       if(n==1) return ;
       ans+=pow(n,3);
       helper(n-1,ans);
       
   }
    int sumOfSeries(int n) {
        // code here
       
        
        int ans=0;
        
        helper(n,ans);
        return ans+1;
        
        
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        Solution ob;
        cout << ob.sumOfSeries(N) << "\n";

        cout << "~"
             << "\n";
    }
}
// } Driver Code Ends