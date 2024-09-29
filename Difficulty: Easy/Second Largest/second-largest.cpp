//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    // Function returns the second
    // largest elements
    int getSecondLargest(vector<int> &arr) {
        // Code Here
        int maxi1=INT_MIN,maxi2=-1;
        for(auto x:arr){
            maxi1=max(x,maxi1);
        }
        
        for(auto x:arr){
            if(maxi2<x && x!=maxi1)
            maxi2=max(x,maxi2);
        }
        return maxi2;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution ob;
        int ans = ob.getSecondLargest(arr);
        cout << ans << endl;
    }
    return 0;
}

// } Driver Code Ends