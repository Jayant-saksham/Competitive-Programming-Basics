#include<bits/stdc++.h>
using namespace std;
int power(int a, int b) {
    if(b==0) {
        return 1;
    }
    if(a == 0) {
        return 0;
    }
    int ans = power(a, b/2);
    ans *= ans;
    if(b&1) {
        ans *= a;
    }
    return ans;
}
int fib(int n) {
    if(n==0 || n==1) {
        return n;
    }
    return fib(n-1) + fib(n-2);
}
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
void powerMatrix(int M[2][2], int n) {
    if(n==0 || n==1) {
        return;
    }
    powerMatrix(M, n/2);
    multiply(M, M);
    if((n%2)!=0) {
        int A[2][2] = {{1,1},{1,0}};
        multiply(M, A);
    }
}
int fibBetter(int n) {
    if(n == 0 || n==1) {
        return n;
    }
    int M[2][2] = {
        {1,1},
        {1,0}
    };
    powerMatrix(M, n-1);
    return M[0][0];
}
int main() {
    cout<<fibBetter(10)<<endl;
    return 0;
}