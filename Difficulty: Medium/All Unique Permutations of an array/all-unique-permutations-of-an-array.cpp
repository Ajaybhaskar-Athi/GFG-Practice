//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    vector<vector<int>> uniquePerms(vector<int> &arr ,int n) {
        // code here
        
        vector<vector<int>>ans;
        map<int,int>count;
        
        for(int i:arr){
            count[i]++;
        }
        vector<int>ds;
        helper(arr,count,ds,ans);
        return ans;
    }
    void helper(vector<int>&arr,map<int,int>&count,vector<int>&ds,vector<vector<int>>&ans){
        int n=arr.size();
        if(ds.size()==n){
            ans.push_back(ds);
            return;
        }
        
        for( auto &pair:count){
            int num=pair.first;
            int &freq=pair.second;
            if(freq>0){
                count[num]--;
                ds.push_back(num);
                helper(arr,count,ds,ans);
                count[num]++;
                ds.pop_back();
            }
        }
        
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        
        cin>>n;
        vector<int> arr(n);
        
        for(int i=0 ; i<n ; i++)
            cin>>arr[i];

        Solution ob;
        vector<vector<int>> res = ob.uniquePerms(arr,n);
        for(int i=0; i<res.size(); i++)
        {
            for(int j=0; j<n; j++)
            {
                cout<<res[i][j]<<" ";
            }
            cout<<"\n";
        }
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends