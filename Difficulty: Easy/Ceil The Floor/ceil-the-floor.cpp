//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User code template

class Solution {
  public:
     int f(vector<int>&arr,int x){
         int l=0,h=arr.size()-1,ans=-1;
         while(l<=h){
             int mid=(l+h)/2;
             if(arr[mid]>x){
                 
                 h=mid-1;
             }else{
                ans=mid;
                 l=mid+1;
             }
         }
         if(ans==-1) return -1;
         return arr[ans];
     }
     int c(vector<int>&arr,int x){
         int l=0,h=arr.size()-1,ans=-1;
         while(l<=h){
             int mid=(l+h)/2;
             if(arr[mid]>=x){
                ans=mid;
                 h=mid-1;
             }else{
                 
                 l=mid+1;
             }
         }
         if(ans==-1) return -1;
         return arr[ans];
     }
    vector<int> getFloorAndCeil(int x, vector<int> &arr) {
        // code here
        sort(arr.begin(),arr.end());
        int fl=f(arr,x);
        int ce=c(arr,x);
        return {fl,ce};
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // Ignore the newline character after t
    while (t--) {
        vector<int> arr;
        int x;
        string input;
        cin >> x;
        cin.ignore();

        getline(cin, input); // Read the entire line for the array elements
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        auto ans = ob.getFloorAndCeil(x, arr);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}
// } Driver Code Ends