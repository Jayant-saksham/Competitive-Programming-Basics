#include<bits/stdc++.h>
using namespace std;
int main() {
    int A[] = {1,4,4,4,4,9,9,10,11};
    int n = sizeof(A)/sizeof(A[0]);
    int x;
    cin>>x;
    int idx = lower_bound(A, A+n, x) - A;
    idx--;
    if(idx>=0) {
        cout<<A[idx]<<endl;
    }
    else {
        cout<<-1<<endl;
    }
    return 0;
}