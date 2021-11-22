#include<bits/stdc++.h>
using namespace std;
int main() {
    int A[] = {1,2,2,2,5,6,7,8,9};
    int n = sizeof(A)/sizeof(A[0]);
    int ans = binary_search(A, A+n, 5);
    // cout<<ans<<endl;

    vector<int> v;
    int key = 9;
    int a = binary_search(v.begin(),v.end(), key);


    int idx = lower_bound(A, A+n, key) - A;
    int idx1 = upper_bound(A, A+n, key) - A;
    cout<<idx1<<endl;

    return 0;
} 

// binary_search - true or false
