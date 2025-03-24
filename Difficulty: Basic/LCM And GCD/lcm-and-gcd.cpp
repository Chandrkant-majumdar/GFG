//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int findlcm(int a,int b){
        int ans=1;
        int l=max(a,b);
        // int b=min(a,b);
        for(int i=2;i<=l;i++){
            
                
                while(a%i==0 && b%i==0){
                a/=i;
                b/=i;
                ans*=i;
            }
             if(a%i==0){
                a/=i;
                ans*=i;
            }else if(b%i==0){
                b/=i;
                ans*=i;
            }
            
            
        }
        return ans*a*b;
    }
    int findgcd(int a,int b){
        if(b==0) return a;
        findgcd(b,a%b);
    }
    vector<int> lcmAndGcd(int a, int b) {
        // code here
        int lcm=findlcm(a,b);
        int gcd=findgcd(a,b);
        return {lcm,gcd};
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int A, B;

        cin >> A >> B;

        Solution ob;
        vector<int> ans = ob.lcmAndGcd(A, B);
        cout << ans[0] << " " << ans[1] << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends