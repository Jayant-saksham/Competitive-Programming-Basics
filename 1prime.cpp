#include<bits/stdc++.h>
using namespace std;
bool isPrime1(int n) {
    for(int i=2;i<=(n-1);i++) {
        if(n%i==0) {
            return false;
        }
    }
    return true;
}
bool isPrime2(int n) {
    for(int i=2;i*i<=n;i++) {
        if(n%i==0) {
            return false;
        }
    }
    return true;
}
void primeSeive1(int n) {
    bool *primes = new bool[n];
    for(int i=0;i<n;i++) {
        primes[i] = true;
    }
    primes[0] = false;
    primes[1] = false;
    for(int i=2;i<=n;i++) {
        if(primes[i]) {
            for(int j=i*2;j<=n;j+=i) {
                primes[j] = false;
            }
        }
    }
    for(int i=0;i<=n;i++) {
        if(primes[i]) {
            cout<<i<<" ";
        }
    }
    delete[] primes;
}
// loglogn
void primeSeive2(int n) {
    bool *primes = new bool[n];
    for(int i=0;i<n;i++) {
        primes[i] = true;
    }
    primes[0] = false;
    primes[1] = false;
    for(int i=2;i*i<=n;i++) {
        if(primes[i]) {
            for(int j=i*i;j<=n;j+=i) {
                primes[j] = false;
            }
        }
    }

    for(int i=0;i<=n;i++) {
        if(primes[i]) {
            cout<<i<<" ";
        }
    }
    delete[] primes;
}
int main() {
    int n;
    cin>>n;
    primeSeive2(n);
    return 0;
}