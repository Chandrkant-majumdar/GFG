//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    string sr(string s){
        int l=s.size();
        string t;
        for(int i=0;i<l;i++){
            if(s[l-i-1]=='('){
                t+=')';
            }
            else if(s[l-i-1]==')'){
                  t+='(';
            }
            else{
                t+=s[l-i-1];
            }
            
        }
        return t;
    }
    string preToInfix(string pre_exp) {
        // Write your code here
        string s=sr(pre_exp);
        stack<string>st;
        
        for(auto x:s){
            if((x>='0' &&x<='9') || (x>='a' &&x<='z') || (x>='A' &&x<='Z') ){
                st.push(string(1,x));
            }
            else{
                string a=st.top();
                st.pop();
                string b=st.top();
                st.pop();
                string res="("+a+x+b+")";
                st.push(res);
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
        cout << obj.preToInfix(prefix) << endl;

        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}

// } Driver Code Ends