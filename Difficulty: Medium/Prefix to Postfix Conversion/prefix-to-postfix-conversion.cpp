//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    string preToPost(string s) {
        
        stack<string>st;
        int l=s.size()-1;
        string res="";
        for(int i=l;i>=0;i-- ){
            
            if((s[i]>='a' && s[i]<='z')||(s[i]>='A' && s[i]<='Z')||(s[i]>='0' && s[i]<='9')){
                
                st.push(string(1,s[i]));
            }else{
                string s1=st.top();
                st.pop();
                string s2=st.top();
                st.pop();
                // res+=s[i]+s1+s2;
                st.push(s1+s2+s[i]);
                
            }
        }
        
        return st.top();
        
        
        
    }
};

//{ Driver Code Starts.

int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input
        string prefix;
        cin >> prefix;

        Solution obj;
        cout << obj.preToPost(prefix) << endl;

        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}

// } Driver Code Ends