#include <bits/stdc++.h>
using namespace std;

//1. Recursion
int Recurrence(vector<int> &arr, int index){
    if(index == 0) return 0;

    int onestep = Recurrence(arr, index-1) + abs(arr[index] - arr[index-1]);
    int twostep = INT_MAX;
    if(index-2 >= 0){
       twostep = Recurrence(arr, index-2) + abs(arr[index] - arr[index-2]);
    }
    return min(onestep,twostep);
}

//2.Memoization
int Memoize(vector<int> &arr, int index, vector<int> &dp){
    if(index == 0) return 0;
    
    if(dp[index] != -1) return dp[index];
    int onestep = Memoize(arr, index-1, dp) + abs(arr[index] - arr[index-1]);
    int twostep = INT_MAX;
    if(index-2 >= 0){
       twostep = Memoize(arr, index-2, dp) + abs(arr[index] - arr[index-2]);
    }
    return dp[index] = min(onestep,twostep);
}

// int main() {
//     int n; cin >> n;
//     vector<int> arr(n);
//     for(int i=0; i<n; i++){
//         cin >> arr[i];
//     }
    
//     vector<int> dp(n, -1);
//     cout << "ans: " << Memoize(arr, n-1, dp) << endl;
//     return 0;
// }

//Tabulation
int main() {
    int n; cin >> n;
    vector<int> arr(n);
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    
    vector<int> dp(n, -1);
    dp[0] = 0;
    for(int index=1; index<n; index++){
        int onestep = dp[index-1] + abs(arr[index] - arr[index-1]);
        int twostep = INT_MAX;
        if(index-2 >= 0){
        twostep = dp[index-2] + abs(arr[index] - arr[index-2]);
        }
        dp[index] = min(onestep,twostep);  
    }
    cout << "ans: " << dp[n-1] << endl;
    return 0;
}

//Space Optimization
int main() {
    int n; cin >> n;
    vector<int> arr(n);
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    
    if(n==1){
        cout << 0;
        return 0;
    }

    int prev1 = 0;
    int prev2 = 0;

    for(int index=1; index<n; index++){
        int onestep = prev1 + abs(arr[index] - arr[index-1]);
        int twostep = INT_MAX;

        if(index-2 >= 0){
        twostep = prev2 + abs(arr[index] - arr[index-2]);
        }

        int curr = min(onestep,twostep);  
        prev2 = prev1;
        prev1 = curr;
    }
    
    cout << "ans: " << prev1 << endl;
    return 0;
}