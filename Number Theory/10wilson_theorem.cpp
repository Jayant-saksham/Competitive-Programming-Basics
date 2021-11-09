#include<bits/stdc++.h>
using namespace std;
void print_primes(int n) {
    long long int f = 1;
    for(int i=2;i<=n;i++) {
        f = f *(i-1);
        if((f+1)%i==0) {
            cout<<i<<" ";
        }
    }
}
int main() {
    int n;
    cin>>n;
    print_primes(n);
    return 0;
}

// Wilson theorem
// (p-1)!%p = (p-1)