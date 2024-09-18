//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
    //Function to check if brackets are balanced or not.
    
    bool ispar(string x)
    {
        stack<char>st;
        for(auto t:x){
            if(st.empty() || t=='(' || t=='{' ||t=='['){
                st.push(t);
            }
            else{
                if(st.top()=='(' && t==')'){
                    st.pop();
                
                    
                }
                else if(st.top()=='[' && t==']'){
                    st.pop();
                }else if(st.top()=='{' && t=='}'){
                    st.pop();
                }else{
                    return false;
                }
            }
        }
        if(st.empty() ) return true;
        
        return false;
        // Your code here
        
    }

};

//{ Driver Code Starts.

int main()
{
   int t;
   string a;
   cin>>t;
   while(t--)
   {
       cin>>a;
       Solution obj;
       if(obj.ispar(a))
        cout<<"balanced"<<endl;
       else
        cout<<"not balanced"<<endl;
   }
}
// } Driver Code Ends