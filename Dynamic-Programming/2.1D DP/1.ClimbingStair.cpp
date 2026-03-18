#include <bits/stdc++.h>
using namespace std;

//Simple Recursion - Bottom Up Approach
int Recursive(int pos){
    //f(1) means we are at 1 so 0 to 1 there is one way, therefore we return 1.
    if(pos == 1) return 1;
    //f(0) means we are already at 0, that means we are already at position that means there is one way.
    if(pos == 0) return 1;

    int left = Recursive(pos-1);
    int right = Recursive(pos-2);

    return left+right;
}

//Memoization - Top - Down Approach
int Memoize(int pos, vector<int> &dp){
    //f(1) means we are at 1 so 0 to 1 there is one way, therefore we return 1.
    if(pos == 1) return 1;
    //f(0) means we are already at 0, that means we are already at position that means there is one way.
    if(pos == 0) return 1;

    if(dp[pos] != -1) return dp[pos];
    int left = Memoize(pos-1, dp);
    int right = Memoize(pos-2, dp);

    return dp[pos] = left+right;
}

// int main() {
//     int n; cin >> n;
//     vector<int> dp(n+1, -1);
//     cout << Memoize(n,dp) << endl;
//     return 0;
// }

//Tabulation - Bottom - Up Approach
int main() {
    int n; cin >> n;
    vector<int> dp(n+1);
    
    dp[0] = 1;
    dp[1] = 1;

    for(int i=2; i<=n; i++){
        int left = dp[i-1];
        int right = dp[i-2];

        dp[i] = left+right; 
    }

    cout << dp[n];
    return 0;
}

//Space Optimization - Get Rid of the space used
int main() {
    int n; cin >> n;
    vector<int> dp(n+1);
    
    if(n == 0 || n == 1){
        cout << 1;
        return 0;
    }
    int prev1 = 1;
    int prev2 = 1;

    for(int i=2; i<=n; i++){
        int curr = prev1 + prev2;
        prev2 = prev1;   // shift first
        prev1 = curr;    //shift second
    }

    cout << prev1;
    return 0;
}