#include<bits/stdc++.h>
using namespace std;
int counter(int A[],int n, int key) {
    int lb = lower_bound(A, A+n, key) - A;
    int ub = upper_bound(A, A+n, key) - A;
    if(lb>=0 && lb<n && ub>0 && ub<=n) {
        return (ub-lb);
    }
    return 0;
}
int main() {
    int A[] = {1,4,4,4,4,9,9,10,11};
    int n = sizeof(A)/sizeof(A[0]);
    int x;
    cin>>x;
    cout<<counter(A, n , x);
    return 0;
}