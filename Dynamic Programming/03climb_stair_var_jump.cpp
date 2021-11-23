#include<bits/stdc++.h>
using namespace std;
int climb_stairs_BU(int n, int *A) {
    int *dp = new int[n+1];
    for(int i=0;i<=n;i++) {
        dp[i] = 0;
    }
    dp[n] = 1;
    for(int i=n-1;i>=0;i--) {
        for(int j=1;j<=A[i];i++) {
            if(i+j<n) {
                dp[i] = dp[i] + dp[i+j];
            }
        }
    }
    int ans =  dp[0];
    delete dp;
    return ans;
}
int main() {
    
    return 0;
}