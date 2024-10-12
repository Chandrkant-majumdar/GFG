//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int pairWithMaxSum(vector<int>& arr) {
        // code here
            if(arr.size() < 1)
            return -1;
            
        int ans = INT_MIN;
        for(int i = 0; i < arr.size()-1;i++)
        {
            int sum = 0;
            ans = max(ans,arr[i]+arr[i+1]);
        }
        
        if(ans == INT_MIN)
            return -1;
        else 
            return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int tc;
    cin >> tc;
    cin.ignore();

    while (tc--) {
        string input;
        getline(cin, input);

        stringstream ss(input);
        vector<int> a;
        int number;
        while (ss >> number) {
            a.push_back(number);
        }

        Solution obj;
        int res = obj.pairWithMaxSum(a);
        cout << res << endl;
    }
}
// } Driver Code Ends