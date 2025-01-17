//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int longestUniqueSubstr(string &s) {
        // code here
        int n=s.size(),ans=0;
        for(int i=0;i<n;i++){
            unordered_map<int,int>mp;
            for(int j=i;j<n;j++){
                
                if(mp.find(s[j])!=mp.end()){
                    mp.clear();
                    break;
                }
                mp[s[j]]++;
             ans = std::max(ans, static_cast<int>(mp.size()));

            }
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {

        Solution obj;
        string s;
        cin >> s;
        cout << obj.longestUniqueSubstr(s) << endl;
        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends