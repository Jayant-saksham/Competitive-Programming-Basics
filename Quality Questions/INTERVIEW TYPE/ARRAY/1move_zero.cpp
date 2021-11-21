#include<bits/stdc++.h>
using namespace std;
void move_zero(int *A, int n) {
    int j = 0;
    int i = 0;
    for(i = 0;i<n;i++) {
        if(A[i]!=0) {
            swap(A[i], A[j]);
            j++;
        }
    }
    return;
}
int main() {
    int n;
    cin>>n;
    int A[n];
    for(int i=0;i<n;i++) {
        cin>>A[i];
    }

    return 0;
}