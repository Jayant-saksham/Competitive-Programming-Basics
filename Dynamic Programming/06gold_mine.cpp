#include<bits/stdc++.h>
using namespace std;
int goldMine(int **A, int n, int m) {
    int **dp = new int*[n];
    for(int i=0;i<n;i++) {
        dp[i] = new int[m];
    }
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            dp[i][j] = 0;
        }
    }
    for(int j=(m-1);j>=0;j--) {
        for(int i=(n-1);i>=0;i--) {
            if(j==(m-1) && i==(n-1)) {
                dp[i][j] = A[i][j];
            }
            else if(j==(m-1)) {
                dp[i][j] = dp[i][j] + dp[i+1][j];
            }
            else if(i==(n-1)) {
                dp[i][j] = dp[i][j] + dp[i][j+1];
            }
            else {
                dp[i][j] = dp[i][j] + max(dp[i+1][j], dp[i][j+1]);
            }
        }
    }
    int ans = INT16_MIN;
    for(int i=0;i<n;i++) {
        ans = max(ans, (dp[i][0]));
    }
    return ans;
}
int main() {
    
    return 0;
}