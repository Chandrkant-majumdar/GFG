//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {

  public:
    vector<int> alternateSort(vector<int>& arr) {
        // Your code goes here
        priority_queue<int>p;
        priority_queue<int,vector<int>,greater<int>>pq;
        for(auto x:arr){
            p.push(x);
            pq.push(x);
        }
        for(int i=0;i<arr.size();i++){
            if(i%2==0){
                arr[i]=p.top();
                p.pop();
            }else{
                arr[i]=pq.top();
                pq.pop();
            }
        }
        return arr;
    }
};


//{ Driver Code Starts.

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        vector<int> ans = obj.alternateSort(arr);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends