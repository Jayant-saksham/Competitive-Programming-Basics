#include<bits/stdc++.h>
using namespace std;
int minimum_steps(int A[], int n, int k) {
    unordered_map<int, int> m;
    for(int i=0;i<n;i++) {
        int x = A[i]%k;
        if(x) {
            m[x]++;
        }
    }
    int ans = 0;
    for(auto i : m) {
        int rem = i.first;
        int count = i.second;
        ans = max(ans, count*k - rem);
    }
    if(ans > 0) {
        ans++;
    }
    return ans;
}
int main() {
    int t;
    cin>>t;
    while(t--) {
        int n,k;
        cin>>n>>k;
        int A[n];
        for(int i=0;i<n;i++)  {
            cin>>A[i];
        }
        cout<<minimum_steps(A, n, k)<<endl;
    }
    return 0;
}