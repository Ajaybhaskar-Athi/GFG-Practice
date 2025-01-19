//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
   int countPartitions(vector<int>& a, int maxSum) {
        int n = a.size(); // size of array.
        int partitions = 1;
        long long subarraySum = 0;
        for (int i = 0; i < n; i++) {
            if (subarraySum + a[i] <= maxSum) {
                // insert element to current subarray
                subarraySum += a[i];
            } else {
                // insert element to next subarray
                partitions++;
                subarraySum = a[i];
            }
        }
        return partitions;
    }
    
    int minTime(vector<int>& arr, int k) {
       int n = arr.size();
        // if (k > n)
        //     return -1;

        int low = *max_element(arr.begin(), arr.end());
        int high = accumulate(arr.begin(), arr.end(), 0);

        while (low <= high) {
            int mid = low + (high - low) / 2;
            int paritions = countPartitions(arr, mid);

            if (paritions > k) {
                low = mid + 1;
            } else
                high = mid - 1;
        }
        return low;
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
        int k;
        cin >> k;
        cin.ignore();
        Solution obj;
        cout << obj.minTime(arr, k) << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends