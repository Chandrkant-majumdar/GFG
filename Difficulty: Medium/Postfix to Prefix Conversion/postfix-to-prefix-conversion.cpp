//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    string postToPre(string s) {
        // Write your code here
        string res="";
        stack<string>st;
        for(auto x:s){
            if((x>='a'&&x<='z')||(x>='A'&& x<='Z')||(x>='0'&&x<='9')){
                st.push(string(1,x));
            }
            else{
                string s1=st.top();
                st.pop();
                string s2=st.top();
                st.pop();
                st.push(x+s2+s1);
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
        string postfix;
        cin >> postfix;

        // char marker; cin >> marker;

        Solution obj;
        cout << obj.postToPre(postfix) << endl;

        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}

// } Driver Code Ends