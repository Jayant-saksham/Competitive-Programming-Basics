#include<bits/stdc++.h>
using namespace std;
int fib(int n) {
    if(n == 0 || n == 1) {
        return n;
    }
    return fib(n-1) + fib(n-2);
}

int betterFib(int n, int *dp) {
    if(n==0 || n==1) {
        return n;
    }
    if(dp[n]>0) {
        return dp[n];
    }
    int ans = betterFib(n-1, dp) + betterFib(n-2, dp);
    dp[n] = ans;
    return ans;
}

int betterFib2(int n) {
    int *dp = new int[n+1];
    dp[0] = 0;
    dp[1] = 1;
    for(int i=2;i<=n;i++) {
        dp[i] = dp[i-1] + dp[i-2];
    }
    int ans = dp[n];
    delete dp;
    return ans;
}

int main(){
    
    return 0;
}