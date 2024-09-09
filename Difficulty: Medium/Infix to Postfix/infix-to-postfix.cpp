//{ Driver Code Starts
// C++ implementation to convert infix expression to postfix
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  
    int p(char i){
        if(i=='+' || i=='-') return 1;
        
        if(i=='*' || i=='/') return 2;
        
        if(i=='^') return 3;
        return 0;
    }
    // Function to convert an infix expression to a postfix expression.
    string infixToPostfix(string s) {
        // Your code here
        stack<char>st;
        
        string res="";
        for(auto x:s){
            if((x>='a' && x<='z') || (x>='A' && x<='Z') ||(x>='0' &&x<='9')){
                res+=x;
            }else if(x=='('){
                
               st.push(x);
            }
            else if(x==')'){
               
                while(st.top()!='('){
                    res+=st.top();
                    st.pop();
                }
                 st.pop();
            }
            else{
                while(!st.empty() && p(x)<=p(st.top())){
                    res+=st.top();
                    st.pop();
                }
                st.push(x);
            }
        }
        while(!st.empty()){
            res+=st.top();
            st.pop();
        }
        return res;
        
    }
};


//{ Driver Code Starts.
// Driver program to test above functions
int main() {
    int t;
    cin >> t;
    cin.ignore(INT_MAX, '\n');
    while (t--) {
        string exp;
        cin >> exp;
        Solution ob;
        cout << ob.infixToPostfix(exp) << endl;
    }
    return 0;
}

// } Driver Code Ends