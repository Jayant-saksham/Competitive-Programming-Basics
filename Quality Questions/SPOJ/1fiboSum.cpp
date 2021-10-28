#include<bits/stdc++.h>
using namespace std;
void multiply(int M[2][2], int A[2][2]) {
    int fvalue = M[0][0] * A[0][0] + M[0][1] * A[1][0];
    int sValue = M[0][0] * A[0][1] + M[0][1] * A[1][1];
    int tValue = M[1][0] * A[0][0] + M[1][1] * A[1][0];
    int lValue = M[1][0] * A[0][1] + M[1][1] * A[1][1];
    M[0][0] = fvalue;
    M[0][1] = sValue;
    M[1][0] = tValue;
    M[1][1] = lValue;
}
void power(int M[2][2], int n) {
    if(n==0 || n == 1) {
        return ;
    }
    power(M ,n/2);
    multiply(M, M);
    if(n&1) {
        int A[2][2] = {{1,1}, {1,0}};
        multiply(M, A);
    }
}
int fib(int n) {
    if(n==0 || n== 1) {
        return n;
    }
    int M[2][2] = {{1,1}, {1,0}};
    power(M ,n-1);
    return M[0][0];
}
int fiboSum(int n, int m) {
    int mod = pow(10,9) + 7;
    if(n == 0) {
        int ans = (fib(m+2) - 1)%mod;
        return ans;
    }
    int ans1 = fib(m+2);
    int ans2 = fib(n+1);
    return (ans1 - ans2)%mod;
}

int main() {
    int t;
    cin>>t;
    while(t--) {
        int n,m;
        cin>>n>>m;
        cout<<fiboSum(n, m)<<endl;
    }
    return 0;
}