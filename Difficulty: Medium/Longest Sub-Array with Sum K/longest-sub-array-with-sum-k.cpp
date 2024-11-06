//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int lenOfLongestSubarr1(vector<int>& arr, int k) {
        // code here
        int ans=0;
        for(int i=0;i<arr.size();i++){
            int sum=0;
            for(int j=i;j<arr.size();j++){
                sum+=arr[j];
                if(sum==k){
                    ans=max(ans,j-i+1);
                }
            }
        }
        return ans;
    }
    int lenOfLongestSubarr(vector<int>& arr, int k) {
        // code here
        int ans=0,sum=0;
        map<int,int>m;
        for(int i=0;i<arr.size();i++){
            sum+=arr[i];
            if(sum==k) ans=max(ans,i+1);
            int rem=sum-k;
            if(m.find(rem)!=m.end()){
                ans=max(ans,i-m[rem]+1);
            }
            if(m.find(sum)==m.end())
            m[sum]=i+1;
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // Ignore newline character after t

    while (t--) {
        vector<int> arr;
        int k;
        string inputLine;

        getline(cin, inputLine); // Read the array input as a line
        stringstream ss(inputLine);
        int value;
        while (ss >> value) {
            arr.push_back(value);
        }

        cin >> k;
        cin.ignore(); // Ignore newline character after k input

        Solution solution;
        cout << solution.lenOfLongestSubarr(arr, k) << "\n";
        cout << "~\n";
    }

    return 0;
}

// } Driver Code Ends