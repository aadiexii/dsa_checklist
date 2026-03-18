/*
Dynamic Programming (DP) – Fibonacci Example

What is Dynamic Programming?

Dynamic Programming is an optimization technique used when a problem has:
1. Overlapping Subproblems
2. Optimal Substructure

Instead of recomputing the same subproblems multiple times,
DP stores previously computed results and reuses them.

Example: Fibonacci Sequence

F(n) = F(n-1) + F(n-2)

Base cases:
F(0) = 0
F(1) = 1
*/

#include <iostream>
#include <vector>
using namespace std;


/*
--------------------------------------------------
1. Recursion (Brute Force)
--------------------------------------------------

Uses the direct recursive definition of Fibonacci.

Time Complexity: O(2^n)
Space Complexity: O(n) (recursion stack)

Problem: Many repeated calculations
*/

int fibRecursion(int n)
{
    if(n <= 1)
        return n;

    return fibRecursion(n-1) + fibRecursion(n-2);
}



/*
--------------------------------------------------
2. Memoization (Top-Down DP)
--------------------------------------------------

Idea:
Store results of subproblems in a DP array to avoid recomputation.

Steps:
1. Use recursion
2. Create DP array
3. Check if value already stored
4. Store result after computing

Time Complexity: O(n)
Space Complexity: O(n)
*/

int fibMemo(int n, vector<int> &dp)
{
    if(n <= 1)
        return n;

    if(dp[n] != -1)
        return dp[n];

    dp[n] = fibMemo(n-1, dp) + fibMemo(n-2, dp);

    return dp[n];
}



/*
--------------------------------------------------
3. Tabulation (Bottom-Up DP)
--------------------------------------------------

Instead of recursion, we build the solution iteratively
starting from the base cases.

Steps:
1. Identify base cases
2. Create DP table
3. Fill the table using iteration

Time Complexity: O(n)
Space Complexity: O(n)
*/

int fibTabulation(int n)
{
    vector<int> dp(n+1);

    dp[0] = 0;
    dp[1] = 1;

    for(int i = 2; i <= n; i++)
    {
        dp[i] = dp[i-1] + dp[i-2];
    }

    return dp[n];
}



/*
--------------------------------------------------
4. Space Optimization
--------------------------------------------------

Observation:
dp[i] depends only on dp[i-1] and dp[i-2]

So we do not need the entire DP array.
We only store the previous two values.

Time Complexity: O(n)
Space Complexity: O(1)
*/

int fibSpaceOptimized(int n)
{
    if(n <= 1)
        return n;

    int prev2 = 0;
    int prev1 = 1;

    for(int i = 2; i <= n; i++)
    {
        int cur = prev1 + prev2;
        prev2 = prev1;
        prev1 = cur;
    }

    return prev1;
}



/*
--------------------------------------------------
Converting Between DP Approaches
--------------------------------------------------

Recursion → Memoization
Focus on:
- Keep same base cases
- Add DP array
- Check if value already computed

Example:
if(dp[n] != -1)
    return dp[n]


Memoization → Tabulation
Focus on:
- Identify base cases
- Remove recursion
- Fill DP table bottom-up


Tabulation → Space Optimization
Focus on:
- Identify which previous states are required
- Store only those values instead of full DP array
*/



/*
--------------------------------------------------
Summary
--------------------------------------------------

Approach            Time Complexity    Space Complexity

Recursion           O(2^n)             O(n)
Memoization         O(n)               O(n)
Tabulation          O(n)               O(n)
Space Optimized     O(n)               O(1)
*/


int main()
{
    int n = 6;

    cout << "Recursion: " << fibRecursion(n) << endl;

    vector<int> dp(n+1, -1);
    cout << "Memoization: " << fibMemo(n, dp) << endl;

    cout << "Tabulation: " << fibTabulation(n) << endl;

    cout << "Space Optimized: " << fibSpaceOptimized(n) << endl;

    return 0;
}