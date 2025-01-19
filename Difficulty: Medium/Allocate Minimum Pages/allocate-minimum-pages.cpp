//{ Driver Code Starts
// Initial function template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// class Solution {
//   public:
//     int findPages(vector<int> &arr, int k) {
//         // code here
//         if(k>arr.size()) return -1;//if students are greater then available books
//         int n=arr.size();
//         int low=*max_element(arr.begin(),arr.end());
//         int high=accumulate(arr.begin(),arr.end(),0);
//         for(int pages=low;pages<=high;pages++){
//             int countStud=findCount(arr,pages);
//             if(countStud==k) return pages;
//         }
//         return low;
//     }
    
//     int findCount(vector<int>&arr,int pages){
//         int students=1,pagesStudent=0;
//         for(int book=0;book<arr.size();book++){
//             if(pagesStudent+arr[book]<=pages)
//                      pagesStudent+=arr[book];
//             else{
//                 students++;
//                 pagesStudent=arr[book];
//             }
//         }
//         return students;
//     }
// };

class Solution {
public:
  int countStudents(vector<int> &arr, int pages) {
    int n = arr.size(); //size of array.
    int students = 1;
    long long pagesStudent = 0;
    for (int i = 0; i < n; i++) {
        if (pagesStudent + arr[i] <= pages) {
            //add pages to current student
            pagesStudent += arr[i];
        }
        else {
            //add pages to next student
            students++;
            pagesStudent = arr[i];
        }
    }
    return students;
}

int findPages(vector<int>& arr,  int m) {
    //book allocation impossible:
    int n=arr.size();
    if (m > n) return -1;

    int low = *max_element(arr.begin(), arr.end());
    int high = accumulate(arr.begin(), arr.end(), 0);
    int res=-1;
    while(low<=high){
        int mid=low+(high-low)/2;
        int studCount=countStudents(arr, mid) ;
       
         if(studCount >m){
            low=mid+1;
        }
        else high=mid-1;
    }
    return low;
}


};



//{ Driver Code Starts.

int main() {
    int test_case;
    cin >> test_case;
    cin.ignore();
    while (test_case--) {

        int d;
        vector<int> arr, brr, crr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        getline(cin, input);
        ss.clear();
        ss.str(input);
        while (ss >> number) {
            crr.push_back(number);
        }
        d = crr[0];
        int n = arr.size();
        Solution ob;
        int ans = ob.findPages(arr, d);
        cout << ans << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends