//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:  
    int findSubString(string& s) {
       unordered_set<char> st;
        int n = s.size();
        for (int i = 0; i < n; i++)
                  st.insert(s[i]);
        int ans = INT_MAX;
        unordered_map<char, int> mp;
        int l = 0, r = 0;
        while (r < n)
        {
            mp[s[r]]++;
            while ( mp.size() == st.size())
            {
                ans = min(ans, r - l + 1);
                mp[s[l]]--;
                if(mp[s[l]]==0)mp.erase(s[l]);
                l++;
            }
            r++;
        }
        return (ans == INT_MAX) ? -1 : ans;
    }
    
};



//{ Driver Code Starts.
//   Driver code
int main() {
    int t;
    cin >> t;
    while (t--) {

        string str;
        cin >> str;
        Solution ob;
        cout << ob.findSubString(str) << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends