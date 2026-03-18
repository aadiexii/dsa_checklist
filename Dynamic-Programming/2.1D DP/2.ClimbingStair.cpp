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
int main() {
    int n; cin >> n;
    cout << Recursive(n) << endl;
    return 0;
}