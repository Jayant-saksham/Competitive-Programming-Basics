#include<bits/stdc++.h>
using namespace std;
int climb_stairs(int n) {
    if(n == 0) {
        return 1;
    }
    else if(n < 0) {
        return 0;
    }
    int a = climb_stairs(n-1);
    int b = climb_stairs(n-2);
    int c = climb_stairs(n-3);
    return (a+b+c);
}

int climb_stair_TD(int n, int *dp) {
    if(n == 0) {
        return 1;
    }
    else if(n<0) {
        return 0;
    }
    if(dp[n]>0) {
        return dp[n];
    }
    int a = climb_stair_TD(n-1, dp);
    int b = climb_stair_TD(n-2, dp);
    int c = climb_stair_TD(n-3, dp);
    int ans = a+b+c;
    dp[n] = ans;
    return ans;
}

int climb_stair_BU(int n) {
    int *dp = new int[1+n];
    for(int i=0;i<=n;i++) {
        dp[i] = 0;
    }
    dp[0] = 1;
    for(int i=1;i<=n;i++) {
        if(i==1) {
            dp[i] = dp[i-1];
        }
        else if(i==2) {
            dp[i] = dp[i-1] + dp[i-2];
        }
        else {
            dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
        }
    }
    int ans = dp[n];
    delete dp;
    return ans;
}
int main() { 
    
    return 0;
}