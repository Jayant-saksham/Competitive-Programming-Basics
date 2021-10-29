#include<bits/stdc++.h>
using namespace std;
string pridiction(int A[], int n) {
    int XOR = A[0];
    for(int i=1;i<n;i++) {
        XOR = XOR^A[i];
    }
    if(XOR!=0 || n&1) {
        return "Player1";
    }
    return "Player2";
}
int main() {
    int A[] = {3,4,5,1,2};
    int n=sizeof(A)/sizeof(A[0]);
    cout<<pridiction(A, n)<<endl;
    return 0;
}