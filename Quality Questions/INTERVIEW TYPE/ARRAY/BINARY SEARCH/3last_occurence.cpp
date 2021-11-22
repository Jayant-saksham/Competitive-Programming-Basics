#include<bits/stdc++.h>
using namespace std;
int main() {
    int A[] = {1,4,4,4,4,9,9,10,11};
    int n = sizeof(A)/sizeof(A[0]);
    int x;
    cin>>x;
    int idx = upper_bound(A, A+n, x) - A;
    idx--;
    if(idx >= 0 && A[idx] == x) {
        cout<<idx<<endl;
    }
    else {
        cout<<-1<<endl;
    }
    return 0;
}